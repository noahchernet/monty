#include "monty.h"

/**
 * push - push @push_num to the top of the stack
 * @stack: the doubly linked list to push @push_num to the top of
 * @l: current line being processed in the monty bytecode f
 * @ln: line number of monty f currently being processed
 * @i: where the caret on the line @ln is in the monty f
 * Return: void
 */

void push(stack_t **stack, char *l, int ln, int i)
{
	/* String returned from strtol, to check if it has run correctly */
	char *return_string = "", *token = strtok(NULL, DELIM);
	char a = (l + i + 4 + 1)[0];
	int not_num = 0, j;
	long push_num;

	if (token)
		push_num = strtol(token, &return_string, 10);
	else
	{
		free_dlistint(*stack);
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		fclose(file);
		exit(EXIT_FAILURE);
	}

	for (j = 1; a != 0; j++)
	{
		a = (l + i + 4 + j)[0];
		if ((a >= 48 && a <= 57) || a == ' ' || a == '\n' || a == 0 || a == '-')
		{
			if ((l + i + 4 + j + 1)[0] == ' ' || (l + i + 4 + j + 1)[0] == '\n')
				break;
			continue;
		}
		else
			not_num = 1;
	}
	if (return_string == l + i + 4 || not_num)
	{
		free_dlistint(*stack);
		fprintf(stderr, "L%d: usage: push integer\n", ln);
		fclose(file);
		exit(EXIT_FAILURE);
	}
	add_dnodeint(stack, (int) push_num);

}
