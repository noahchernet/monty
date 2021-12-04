#include "monty.h"

/**
 * add_dnodeint - adds a new dlistint_t to the top of the list
 * @stack: the first element of the doubly linked list
 * @n: the integer which will be in the new node of the list
 *
 * Return: new_node, the newly initialized node added to the top of the list
 *		   NULL if malloc fails
 */
stack_t *add_dnodeint(stack_t **stack, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (!*stack)
	{
		*stack = new_node;
		return (new_node);
	}

	new_node->next = *stack;
	(*stack)->prev = new_node;
	*stack = new_node;

	return (new_node);
}

/**
 * print_dlistint - prints the contents of the doubly linked list @h
 * @stack: the first item in the doubly linked list
 *
 * Return: size of the list
 */
size_t print_dlistint(const stack_t *stack)
{

	int nodes = 0;

	if (stack == NULL)
		return (0);

	while (stack != NULL)
	{
		printf("%d\n", stack->n);
		nodes++;
		stack = stack->next;
	}

	return (nodes);
}


/**
 * free_dlistint - frees the mem occupied by the doubly linked list @head
 * @head: the first item in the doubly linked list
 *
 * Return: void
 */
void free_dlistint(stack_t *head)
{
	if (!head)
		return;
	while (head->next)
	{
		free(head->prev);
		head = head->next;
	}
	free(head->prev);
	free(head);
}
