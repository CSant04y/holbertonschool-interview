#include "lists.h"


/**
 * check_cycle - This checks to see if a Singly linked list is a circular
 * @list: This is the linked list head being passed to be checked
 *
 * Return: 1 for cycle and 0 for no cycle
 */
int check_cycle(listint_t *list)
{
	listint_t *tortise = list, *hare = list;


	while (tortise && hare && hare->next)
	{
		tortise = tortise->next;
		hare = hare->next->next;

		if (tortise == hare)
			return (1);
	}

	return (0);
}
