#include "sort.h"


listint_t *swap_list(listint_t *pred, listint_t *current)
{
	listint_t *tmp1, *tmp2;

	tmp1 = pred->prev;
	tmp2 = current->prev;

	pred->next = current->next;
	pred->prev = current;
	if (current->next != NULL)
		current->next->prev = pred;
	current->next = pred;
	current->prev = tmp1;
	if (tmp2 != NULL)
		tmp1->next = current;
	return current;
}


/**
 * insertion_sort_list - function that sorts a doubly linked list of integers
 * 			in ascending order using the Insertion sort algorithm
 * @list: The pointer to the head of the list
 * Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *current, *key, *pred;

	if (list->next != NULL)
	{
		current = list->next;
		for (; current != NULL; current = current->next)
		{
			key = current;
			pred = current->prev;
			while (pred != NULL && (pred->n > key->n))
			{
				pred = swap_list(&pred, &key);
				pred = key->prev;
			}
		}
	}
}
