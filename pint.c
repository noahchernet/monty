#include "monty.h"

/**
 * pint - print the number on the top of the stack
 * @stack: the stack generated by the monty bytecode @file
 * @ln: line number currently being operated on @file
 */
void pint(stack_t **stack, int ln)
{
	if (*stack)
		printf("%i\n", (*stack)->n);
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", ln);
		fclose(file);
		exit(EXIT_FAILURE);
	}
}
