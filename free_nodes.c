#include "monty.h"

/**
 * free_nodes - release buffer
 */
void free_nodes(void)
{
	stack_t *buff;

	while (head)
	{
		buff = head;
		head = head->next;
		free(buff);
	}
}
