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

/**
 * delete_dnodeint_at_index - deletes the node at @index of dlistint_t linked
 * list
 * @head: the first node in the doubly linked list
 * @index: the index of the node to be deleted
 * Return: 0 if it succeeds, -1 if it fails
 */
int delete_dnodeint_at_index(stack_t **head, unsigned int index)
{
	stack_t *old, *prev;

	if (!head)
		return (-1);

	old = *head;

	if (!old)
		return (-1);

	if (index)
	{
		prev = old;

		while (--index && prev->next)
			prev = prev->next;

		if (index)
			return (-1);

		old = prev->next;

		if (!old)
			return (-1);

		prev->next = old->next;

		if (prev->next)
			prev->next->prev = prev;
	}
	else
	{
		*head = old->next;

		if (*head)
			(*head)->prev = NULL;
	}
	free(old);

	return (1);
}

/**
 * add_dnodeint_end - adds node at the end of the doubly linked list with the
 * head of the list @head
 * @head: first item of the doubly linked list
 * @n: n value of the newly added item in the list
 *
 * Return: address of new list, NULL if it failed
 */
stack_t *add_dnodeint_end(stack_t **head, const int n)
{
	stack_t *new_node = malloc(sizeof(stack_t));
	stack_t *head_copy = *head;

	if (!new_node)
	{
		free(new_node);
		return (NULL);
	}
	new_node->n = n;
	new_node->prev = NULL;
	new_node->next = NULL;

	if (!(*head))
	{
		*head = new_node;
		return (new_node);
	}
	while (head_copy->next)
		head_copy = head_copy->next;

	head_copy->next = new_node;
	new_node->prev = head_copy;
	return (new_node);

}
