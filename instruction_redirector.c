#include "monty.h"

/**
 * get_instruction_func - runs the function that matches the opcode @s
 * @s: the opcode passed
 * Return: void
 */
void (*get_instruction_func(const char *s))(stack_t **stack, unsigned int
line_number)
{
	instruction_t ins[] = {
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add}
	};
	int i;
	int size_of_ins = (int) ((int) sizeof(ins) / sizeof(ins[0]));

	for (i = 0; i < size_of_ins; i++)
	{
		if (*ins[i].opcode == *s)
			return (ins[i].f);
	}

	return NULL;
}
