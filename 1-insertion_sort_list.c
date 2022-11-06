#include "sort.h"

/**
 * nodes_swap - swap two nodes in the doubly-linked list
 * @h: The of the list
 * @no1: first node that must swap
 * @no2: second node that must swap
 * Return: Void
 */
void nodes_swap(listint_t **h, listint_t **no1, listint_t *no2)
{
	(*no1)->next = no2->next;

	if (no2->next != NULL)
		no2->next->prev = *no1;

	no2->prev = (*no1)->prev;
	no2->next = *no1;

	if ((*no1)->prev == NULL)
		*h = no2;
	else
		(*no1)->prev->next = no2;
	(*no1)->prev = no2;
	*no1 = no2->prev;
}
/**
 * insertion_sort_list - sort Doubly_linked list using insertion sort alogrithm
 * @list: The Doubly Linked list
 * Return: Void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *head, *node;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	for (head = (*list)->next; head != NULL; head = head->next)
	{
		node = head->prev;
		while (node != NULL && head->n < node->n)
		{
			nodes_swap(list, &node, head);
			print_list((const listint_t *)*list);
		}
	}
}
