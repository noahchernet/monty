#include "monty.h"

/**
 * main - program starts here
 * @argc: number of arguments passed
 * @argv: array of the arguments that were passed
 * Return: 0 if successful, 1 if program failed with appropriate error in
 * STDERR_FILENO
 */
int main(int argc, char **argv)
{
	FILE *file;
	char *opcodes[7] = {"push", "pall", "pint", "swap", "pop", "add", "nop"};
	if (argc < 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (!file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[0]);
		exit(EXIT_FAILURE);
	}

	pl(file, opcodes);
	return (0);
}

/**
 * substr - gets the substring of @source and sets it to @target
 * @source: the string where the substring will be taken from
 * @target: where the substring will be placed
 * @from: the starting index
 * @to: the final index
 * Return: 0 if successful, 1 if it failed
 */
char *substr(const char *source, char *target, int from, int to)
{
	int length = 0;
	int i = 0, j;

	/* Get the length of the string */
	while (source[i++] != '\0')
		length++;

	if (from < 0 || from > length)
		return (0);
	if (to > length)
		to = length - 1;

	for (i = from, j = 0; i <= to; i++, j++)
		target[j] = source[i];

	/* Assign NULL at the end of string */
	target[j] = '\0';

	return (target);
}

void pl(FILE *file, char **opcodes)
{
	char l[1000];
	char *opcode_large = malloc(sizeof(char) * 4);
	char *opcode_small = malloc(sizeof(char) * 3);
	int i, j, ln = 0, opcode_executed;

	while (fgets(l, sizeof(l), file) != NULL)
	{
		ln++, opcode_executed = 0;
		for (i = 0; i < 1000 && l[i] != 0; i++)
		{
			if (l[i] == ' ' || l[i] == '\t' || l[i] == 0 || l[i] == '\n')
				continue;

			for (j = 0; j < 7; j++)
			{
				/* Check if line has one of the 4 character opcodes */
				if ((!strcmp(substr(l, opcode_large, i, i + 3), opcodes[j]) &&
					(l[i + 4] == ' ' || l[i + 4] == 0 || l[i + 4] == '\n') ) ||
					(!strcmp(substr(l, opcode_small, i, i + 2), opcodes[j]) &&
					 (l[i + 3] == ' ' || l[i + 3] == 0 || l[i + 3] == '\n')))
				{
					process_opcode(l, ln, i, j, opcodes);
					opcode_executed = 1;
				}
			}
			if (!opcode_executed)
			{
				free(opcode_large);
				free(opcode_small);
				dprintf(STDERR_FILENO, "L%d: unknown instruction %s\n",
						ln, l + i);
				exit(EXIT_FAILURE);
			}
		}
	}
}

/**
 * process_opcode - runs opcode or finds error in the line passed
 * @l: the current line being processed by the interpreter
 * @i: index where the opcode starts in @line
 * @opcodes: list of available executable opcodes
 * @opcode_index: the index of the opcode in @opcodes to be executed
 * Return: void
 */
void process_opcode(char *l, int ln, int i, int j, char **opcodes)
{
	char *return_string = "";
	long push_num;

	if (!strcmp(opcodes[j], "push"))
	{
		push_num = strtol(l + i + 4, &return_string, 10);
		if (return_string == l + i + 4)
		{
			dprintf(STDERR_FILENO, "L%d: usage: push integer\n", ln);
			exit(EXIT_FAILURE);
		}
		printf("OP_CODE = %s, VALUE = %ld\n", opcodes[j], push_num);
	} else
		printf("OP_CODE = %s\n", opcodes[j]);
}
