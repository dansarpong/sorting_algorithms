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
 * insertion_sort_list - function to sort with insertion sort
 * @list: list to be sorted
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *temp, *cur, *holder;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = (*list)->next;
	while (temp)
	{
		cur = temp;
		holder = cur->prev;
		temp = temp->next;
		while (holder && holder->n > cur->n)
		{
			swap(&holder, &cur);
			if (!cur->prev)
				*list = cur;
			holder = cur->prev;
			print_list(*list);
		}
	}
}
