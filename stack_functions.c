#include "monty.h"

/**
 * add_dnodeint - adds a new dlistint_t to the top of the list
 * @head: the first element of the doubly linked list
 * @n: the integer which will be in the new node of the list
 *
 * Return: new_node, the newly initialized node added to the top of the list
 *		   NULL if malloc fails
 */
stack_t *add_dnodeint(stack_t **head, const int n)
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

	if (!*head)
	{
		*head = new_node;
		return (new_node);
	}

	new_node->next = *head;
	(*head)->prev = new_node;
	*head = new_node;

	return (new_node);
}

/**
 * print_dlistint - prints the contents of the doubly linked list @h
 * @h: the first item in the doubly linked list
 *
 * Return: size of the list
 */
size_t print_dlistint(const stack_t *h)
{

	int nodes = 0;

	if (h == NULL)
		return (0);

	while (h != NULL)
	{
		printf("%d\n", h->n);
		nodes++;
		h = h->next;
	}

	return (nodes);
}
