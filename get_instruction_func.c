#include "monty.h"

/**
 * get_instruction_func - loads appropriate function for passed opcode
 * @line_number: the line number being processed in the Monty bytecode
 * Return: the function for the opcode
 */
void (*get_instruction_func(char *s))(stack_t **stack,
	unsigned int line_number)
{
	int i;
	instruction_t *instructions = NULL;
/*
*	{
*			{"push", push},
*			{"pall", pall},
*			{"pint", pint},
*			{"swap", swap},
*			{"pop", pop},
*			{"add", add},
*			{"nop", nop}
*	};
*/

	for (i = 0; i < 6; i++)
	{
		if (!strcmp(instructions[i].opcode, s))
			return (instructions[i].f);
	}

	return (NULL);
}
