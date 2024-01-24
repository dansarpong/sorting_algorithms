#include "sort.h"

/**
 * swap - swap two nodes in a list
 * @node1: first node to swap
 * @node2: second node to swap
 */
void swap(listint_t **node1, listint_t **node2)
{
	listint_t *prev, *next;

	prev = (*node1)->prev;
	next = (*node2)->next;

	if (prev)
		prev->next = (*node2);
	if (next)
		next->prev = (*node1);

	(*node2)->prev = prev;
	(*node2)->next = (*node1);

	(*node1)->next = next;
	(*node1)->prev = (*node2);
}

/**
 * cocktail_sort_list - function to sort with cocktail shaker sort
 * @list: list to be sorted
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *cur, *next;
	int done;

	if (!list || !(*list))
		return;
	cur = *list;
	do {
		done = 0;
		while (cur->next)
		{
			next = cur->next;
			if (cur->n > next->n)
			{
				done = 1;
				swap(&cur, &next);
				if (!next->prev)
					*list = next;
				print_list(*list);
			}
			else
				cur = cur->next;
		}
		if (!done)
			break;
		cur = cur->prev;
		while (cur)
		{
			next = cur->next;
			if (cur->n > next->n)
			{
				done = 1;
				swap(&cur, &next);
				if (!next->prev)
					*list = next;
				print_list(*list);
			}
			else
				cur = cur->prev;
		}
	} while (!done);
}
