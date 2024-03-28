#include "monty.h"

/**
 * open_f - opens a file
 * @filename: the file namepath
 * Return: void
 */
void open_f(char *filename)
{
	FILE *file = fopen(filename, "r");

	if (!filename || !file)
	{
		error_handle(2, filename);
	}
	read_f(file);
	fclose(file);
}


/**
 * read_f - reads a file
 * @file: pointer to file descriptor
 * Return: void
 */
void read_f(FILE *file)
{
	int line = 1;
	char buffer[MAX_SIZE];

	while (fgets(buffer, MAX_SIZE, file) != NULL)
	{
		extract_line(buffer, line);
		line++;
	}
}

/**
 * extract_line - Separates each line into tokens to determine
 * which function to call
 * @buffer: line from the file
 * @line: line number
 * if 1 nodes will be entered as a queue
 * Return: Returns 0 if the opcode is stack. 1 if queue.
 */
void extract_line(char *buffer, int line)
{
	char *function, *value;
	const char *delim = "\n ";

	if (buffer == NULL)
	{
		error_handle(4);
	}
	function = strtok(buffer, delim);
	if (function == NULL)
	{
		return;
	}
	value = strtok(NULL, delim);

	find_func(function, value, line);
}

/**
 * find_func - find the appropriate function for the opcode
 * @function: opcode
 * @value: argument of opcode
 * @line: line number
 * if 1 nodes will be entered as a queue.
 * Return: void
 */
void find_func(char *function, char *value, int line)
{
	int i;
	int found = 1;

	instruction_t func_list[] = {
		{"push", add_to_stack},
		{"pall", print_stack},
		{"pint", print_top},
		{"pop", pop_top},
		{"nop", nop},
		{"swap", swap_nodes},
		{"add", add_stack},
	};

	if (function[0] == '#')
	{
		return;
	}

	for (i = 0; func_list[i].opcode != NULL; i++)
	{
		if (strcmp(function, func_list[i].opcode) == 0)
		{
			excute_fun(func_list[i].f, function, value, line);
			found = 0;
		}
	}
	if (found == 1)
	{
		error_handle(3, line, function);
	}
}

/**
 * excute_fun - Calls the required function.
 * @func: Pointer to the function that is about to be called.
 * @function: string representing the opcode.
 * @value: string representing a numeric value.
 * @line: line numeber for the instruction.
 * if 1 nodes will be entered as a queue.
 */
void excute_fun(op_func func, char *function, char *value, int line)
{
	stack_t *node;
	int i = 0;

	if (strcmp(function, "push") == 0)
	{
		if (value != NULL && value[0] == '-')
		{
			i = 1;
		}
		if (value == NULL)
		{
			error_handle(5, line);
		}
		for (; value[i] != '\0'; i++)
		{
			if (isdigit(value[i]) == 0)
				error_handle(5, line);
		}
		node = create_node(atoi(value));
		func(&node, line);
	}
	else
	{
		func(&head, line);
	}
}
