#include <stdio.h>
#include <stdlib.h>
#include "lists.h"
 

/**
 * is_palindrome- prints all elements of a listint_t list
 * @head: pointer to head of list
 * Return: 1 if palindrome, 0 if not
 */
int is_palindrome(listint_t **head)
{
	size_t itr, itr2;
    int array[1000000];
    listint_t *temp;

    temp = *head;
    if (temp == NULL)
        return (1);

	if (temp != NULL)
	{
		for (itr2 = 0; temp != NULL; temp = temp->next, itr2++)
            array[itr2] = temp->n;
	}

    for (itr = 0; itr < itr2 / 2; itr++)
    {
        if (array[itr] != array [itr2 - itr - 1])
            return(0);
    }
    return (1);
}
