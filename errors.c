#include "monty.h"

/**
 * error_handle - prints error message while detection
 * @code: The error codes are the following:
 * (1) => The user does not give any file or more than one file to the program
 * (2) => The file provided is not a file that can be opened or read
 * (3) => The file provided contains an invalid instruction
 * (4) => When the program is unable to malloc more memory
 * (5) => When the parameter passed to the instruction "push" is not an int
 * (6) => When the stack it empty for pint
 * (7) => When the stack it empty for pop
 * (8) => When stack is too short for operation
 */
void error_handle(int code, ...)
{
	va_list argument;
	char *opcode;
	int n;

	va_start(argument, code);
	switch (code)
	{
		case 1:
			fprintf(stderr, "USAGE: monty file\n");
			break;
		case 2:
			fprintf(stderr, "Error: Can't open file %s\n",
				va_arg(argument, char *));
			break;
		case 3:
			n = va_arg(argument, int);
			opcode = va_arg(argument, char *);
			fprintf(stderr, "L%d: unknown instruction %s\n", n, opcode);
			break;
		case 4:
			fprintf(stderr, "Error: malloc failed\n");
			break;
		case 5:
			fprintf(stderr, "L%d: usage: push integer\n", va_arg(argument, int));
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}

/**
 * error_handle_2 - handles errors
 * @code: The error codes are the following:
 * (6) => When the stack it empty for pint
 * (7) => When the stack it empty for pop
 * (8) => When stack is too short for operation
 * (9) => Division by zero
 */
void error_handle_2(int code, ...)
{
	va_list argument;
	int line;
	char *func;

	va_start(argument, code);

	switch (code)
	{
		case 1:
			line = va_arg(argument, int);
			func = va_arg(argument, char *);
			fprintf(stderr, "L%d: can't %s, stack too short\n", line, func);
			break;
		case 2:
			line = va_arg(argument, int);
			fprintf(stderr, "L%d: division by zero\n", line);
			break;
		default:
			break;
	}
	free_nodes();
	exit(EXIT_FAILURE);
}
