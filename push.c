#include "monty.h"

/**
 *
 */

void push(stack_t **stack, char *l, int ln, int i)
{
	/* String returned from strtol, to check if it has run correctly */
	char *return_string = "";

	long push_num = strtol(l + i + 4, &return_string, 10);

	if (return_string == l + i + 4)
	{
		free_dlistint(*stack);
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, (int) push_num);

}
