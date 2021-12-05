#include "monty.h"

void add(stack_t **stack, unsigned int ln)
{
	int sum;
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", ln);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	sum = (*stack)->n + (*stack)->next->n;
	pop(stack, ln);
	pop(stack, ln);
	add_dnodeint(stack, sum);
}
