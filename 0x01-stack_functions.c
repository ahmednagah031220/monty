#include "monty.h"

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

void swap_nodes(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)(line_number);
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	if (tmp->next != NULL)
	{
		tmp->next->prev = *stack;
	}
	tmp->next = *stack;
	(*stack)->prev = tmp;
	tmp->prev = NULL;
	*stack = tmp;
}

void add_stack(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (!(*stack) || stack == NULL)
	{
		error_handle_2(1, line, "add");
	}

	tmp = *stack;
	if (tmp->next != NULL)
	{
		tmp->next->n = tmp->next->n + tmp->n;
		(*stack) = tmp->next;
		free(tmp);
	}
	else
	{
		error_handle_2(1, line, "add");
	}
}
