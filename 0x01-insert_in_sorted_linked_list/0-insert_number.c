#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_node - Traverses through a singly linked list with two pointers
 * @head: The pointer to the linked list
 * @number: the number that is to be inserted into linke list
 * Return: always 0
 */

listint_t *insert_node(listint_t **head, int number)
{
	listint_t *new, *current, *temp;

	current = *head;
	new = malloc(sizeof(listint_t));
	if (new == NULL)
		return (NULL);

	new->n = number;
	if (*head == NULL)
	{
		new->next = NULL;
		*head = new;
	}
	else if (number < current->n)
	{
		new->next = current;
		*head = new;
	}
	else
	{
		while (current->next != NULL)
		{
			if (number < current->next->n)
				break;
			current = current->next;
		}
		temp = current->next;
		current->next = new;
		new->next = temp;
	}
	return (new);
}
