#include "sort.h"

/**
 * swapping - swaps two nodes
 * @list: listint_t list
 * @node: node to be swapped
 */
void swapping(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;
	if (node->prev)
		node->prev->next = node->next;
	else
		*list = node->next;
	node->prev = node->next;
	node->next = node->next->next;
	node->prev->next = node;
	if (node->next)
		node->next->prev = node;
}


/**
  *cocktail_sort_list - sort linked list using cocktail sort
  *@list: doubly linked list to be sorted
  *
  *Return: void
  */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *node = *list;

	if (*list == NULL || list == NULL || (*list)->next == NULL)
	{
		return;
	}
	while (swapped != 0)
	{
		swapped = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				swapping(list, node);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				node = node->next;
			}
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				swapping(list, node->prev);
				swapped = 1;
				print_list(*list);
			}
			else
			{
				node = node->prev;
			}
		}
	}
}
