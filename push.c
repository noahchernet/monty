#include "monty.h"

FILE *file;
/**
 * push - push @push_num to the top of the stack
 * @stack: the doubly linked list to push @push_num to the top of
 * @l: current line being processed in the monty bytecode file
 * @ln: line number of monty file currently being processed
 * @i: where the caret on the line @ln is in the monty file
 * Return: void
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
		fclose(file);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, (int) push_num);

}
