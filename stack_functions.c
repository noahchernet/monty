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

	printf("---\n");
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
	stack_t *h = *head;  /* Copy head for easier usage */
	stack_t *head_backup = *head;  /* Backup to restore when func returns */
	unsigned int node = -1;

	if (!h || (!h->next && h->n == -1 && !h->prev))
	{
		head = NULL;
		return (-2);
	}
	while (h)
	{
		if (node == index)
		{
			if (!h->prev)
			{
				if (h->next)
				{
					h->next->prev = NULL;
					*head = h->next;
				}
				free(h);
				return (0);
			}
			if (!h->next)
			{
				if (h->prev)
					h->prev->next = NULL;
				free(h);
				return (0);
			}
			h->next->prev = h->prev;
			h->prev->next = h->next;
			free(h);
			return (0);
		}
		node++;
		h = h->next;
	}
	*head = head_backup;
	return (-2);
}
