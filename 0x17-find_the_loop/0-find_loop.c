#include "lists.h"
#include <stdio.h>

/**
 * find_listint_loop - This function finds a loop in linked list 
 * 
 * @head: This is the head of the Linked list that is passed in
 * @return listint_t* 
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *turtle = head, *hare = head;

	if (!head || !head->next)
		return (NULL);


	while (turtle->next && hare->next->next)
	{
		turtle = turtle->next;
		hare = hare->next->next;
		if(turtle == hare)
		{	
			turtle = head;
			while (turtle != hare)
			{	
				turtle = turtle->next;
				hare = hare->next;
			}
			return (hare);
		}
	}

	return (NULL);
}
