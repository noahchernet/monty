#include "monty.h"


/**
 * pstr - prints each character in the stack
 * @stack: the doubly linked list to push @push_num to the top of
 * Return: void
 */
void pstr(stack_t **stack)
{
	stack_t *head = *stack;

	while (head)
	{
		if (head->n <= 0 || head->n > 127)
			break;
		printf("%c", head->n);
		head = head->next;
	}
	printf("\n");
}
