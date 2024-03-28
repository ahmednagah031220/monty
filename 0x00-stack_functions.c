#include "monty.h"

/**
 * add_to_stack - funciton of adding nodes to the stack
 * @new_node: new node pointer
 * @line: to represent the line number of the opcode
 */
void add_to_stack(stack_t **new_node, unsigned int line)
{
	stack_t *tmp;

	(void)(line);
	if (new_node == NULL || *new_node == NULL)
		exit(EXIT_FAILURE);
	if (head == NULL)
	{
		head = *new_node;
		return;
	}
	tmp = head;
	head = *new_node;
	head->next = tmp;
	tmp->prev = head;
}

/**
 * print_stack - adds a node to the stack
 * @stack: pointer to a pointer refering to the top node of the stack
 * @line_number: line number
 */
void print_stack(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)(line_number);
	if (stack == NULL)
		exit(EXIT_FAILURE);
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pop_top - adds a node to the stack
 * @stack: pointer to a pointer refering to the top node of the stack
 * @line_number: line number
 */
void pop_top(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)(line_number);
	tmp = *stack;
	*stack = tmp->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}

/**
 * print_top - top node of stack printing
 * @stack: pointer to a pointer refering to the top node of the stack
 * @line_number: line number
 */
void print_top(stack_t **stack, unsigned int line_number)
{
	(void)(line_number);
	printf("%d\n", (*stack)->n);
}
