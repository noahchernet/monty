#ifndef MONTY_MONTY_H
#define MONTY_MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

char *substr(const char *source, char *target, int from, int to);

void process_lines(FILE *file, char **opcodes, stack_t **stack);
void process_opcode(char *l, int ln, int i, int j, char **opcodes, stack_t
**stack);

/**
 * get_instruction_func - loads appropriate function for passed opcode
 * @line_number: the line number being processed in the Monty bytecode
 * Return: the function for the opcode
 */
void (*get_instruction_func(char *s))(stack_t **stack,
		unsigned int line_number);

/* Opcode functions */
stack_t *add_dnodeint(stack_t **head, int n);
size_t print_dlistint(const stack_t *h);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

#endif /* MONTY_MONTY_H */
