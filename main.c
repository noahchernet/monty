#include "monty.h"
#include "stdio.h"

FILE *file;
/**
 * main - program starts here
 * @argc: number of arguments passed
 * @argv: array of the arguments that were passed
 * Return: 0 if successful, 1 if program failed with appropriate error in
 * STDERR_FILENO
 */
int main(int argc, char **argv)
{
	char *opcodes[7] = {"push", "pall", "pint", "swap", "pop", "add", "nop"};
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	process_lines(opcodes, &stack);
	free_dlistint(stack);
	fclose(file);
	return (0);
}

/**
 * process_lines - process one line at a time and interpret Monty bytecode
 * @opcodes: supported Monty bytecode operation codes
 * @stack: the stack to be modified
 * Return: void
 */
void process_lines(char **opcodes, stack_t **stack)
{
	char l[1000];
	char opcode_large[4];  /* For opcodes that are 4 chars in length */
	char opcode_small[3];  /* For opcodes that are 3 chars in length */
	int i, j, ln = 0, opcode_executed;

	while (fgets(l, sizeof(l), file) != NULL)
	{
		ln++;
		for (i = 0; i < 1000 &&  l[i] != 0; i++)
		{
			opcode_executed = 0;
			if (l[i] == ' ' || l[i] == '\t' || l[i] == 0 || l[i] == '\n')
				continue;

			for (j = 0; j < 7 && !opcode_executed; j++)
			{
				/* Check if line has one of the 4 or 3 character opcodes */
				if ((!strncmp(strncpy(opcode_large, l + i, 4),
					opcodes[j], 4) && (l[i + 4] == ' ' || l[i + 4] == 0 ||
					  l[i + 4] == '\n')) || (!strncmp(strncpy(opcode_small, l
					  + i, 3), opcodes[j], 3) && (l[i + 3] == ' ' || l[i + 3]
					  == 0 || l[i + 3] == '\n')))
				{
					process_opcode(l, ln, i, j, opcodes, stack);
					opcode_executed = 1;
				}
			}
			if (!opcode_executed)
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
						ln, strtok(l, " \n\t\r\a"));
				fclose(file);
				exit(EXIT_FAILURE);
			} break;
		}
	}
}

/**
 * process_opcode - runs opcode or finds error in the line passed
 * @l: the current line being processed by the interpreter
 * @i: index where the opcode starts in @line
 * @opcodes: list of available executable opcodes
 * @j: the index of the opcode in @opcodes to be executed
 * @ln: the current line number of the file being processed
 * @stack: the doubly linked list to be modified
 * Return: void
 */
void process_opcode(char *l, int ln, int i, int j, char **opcodes, stack_t
**stack)
{
	if (!strcmp(opcodes[j], "push"))
		push(stack, l, ln, i);
	else if (!strcmp(opcodes[j], "pall"))
		print_dlistint(*stack);
	else if (strcmp(opcodes[j], "nop") != 0)
		get_instruction_func(opcodes[j])(stack, ln);
	else if (!strcmp(opcodes[j], "nop"))
		return;

}
