#ifndef MONTY_MONTY_H
#define MONTY_MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#define DELIM " \n\t\r\a"

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
extern FILE *file;

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
/**
 * get_instruction_func - returns the right function for the opcode @s
 * @ln: the line number currently being processed in @file
 * Return: void
 */
void (*get_instruction_func(const char *s))(stack_t **stack,
											unsigned int ln);


void process_lines(char **opcodes, stack_t **stack, int supported_opcodes);
void process_opcode(char *l, int ln, int i, int j, char **opcodes, stack_t
**stack);


/* Stack functions */
stack_t *add_dnodeint(stack_t **stack, int n);
size_t print_dlistint(const stack_t *stack);
void free_dlistint(stack_t *head);
int delete_dnodeint_at_index(stack_t **head, unsigned int index);
stack_t *add_dnodeint_end(stack_t **head, int n);

/*
 * Opcode functions
 * ln - stands for line number being processed when the opcode is called
 */

void push(stack_t **stack, char *l, int ln, int i);
void pint(stack_t **stack, unsigned int ln);
void pop(stack_t **stack, unsigned int ln);
void swap(stack_t **stack, unsigned int ln);
void add(stack_t **stack, unsigned int ln);
void sub(stack_t **stack, unsigned int ln);
void mul(stack_t **stack, unsigned int ln);
void div_(stack_t **stack, unsigned int ln);
void mod(stack_t **stack, unsigned int ln);
void pchar(stack_t **stack, unsigned int ln);
void pstr(stack_t **stack);
void rotl(stack_t **stack);
void rotr(stack_t **stack);

#endif /* MONTY_MONTY_H */
