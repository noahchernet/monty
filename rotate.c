#include "monty.h"


/**
 * rotl - rotates the stack to the top, the top element of the stack becomes
 * the last one, and the second top element of the last stack becomes the
 * first one
 * @stack: the doubly linked list to push @push_num to the top of
 * Return: void
 */
void rotl(stack_t **stack)
{
	stack_t *head = *stack;
	int top_num;

	if (!head || !head->next)
		return;

	top_num = head->n;
	delete_dnodeint_at_index(stack, 0);
	add_dnodeint_end(stack, top_num);
}

/**
 * rotr - rotates the stack to the bottom, the last element of the stack
 * becomes the top element of the stack
 * @stack: the doubly linked list to push @push_num to the top of
 * Return: void
 */
void rotr(stack_t **stack)
{
	stack_t *head = *stack;
	int bottom_num, bottom_element_index = 0;

	if (!head || !head->next)
		return;

	while (head->next)
	{
		head = head->next;
		bottom_element_index++;
	}
	bottom_num = head->n;

	delete_dnodeint_at_index(stack, bottom_element_index);
	add_dnodeint(stack, bottom_num);
}
