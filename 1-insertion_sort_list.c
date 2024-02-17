#include "sort.h"

/**
 * sort_swap - rearranges elements to their propper position
 * 
 * @list: list to be printed
 * @node: element to be sorted 
*/
void sort_swap(listint_t **list, listint_t *node)
{
	listint_t *temp;

	if (node->n < node->prev->n)
	{
		temp = node->prev->prev;
		if (node->next != NULL)
			node->next->prev = node->prev;
		if (node->prev->prev != NULL)
			node->prev->prev->next = node;
		else
			*list = node;
		node->prev->next = node->next;
		node->prev->prev = node;
		node->next = node->prev;
		node->prev = temp;
		print_list(*list);
		if (node->prev != NULL)
		{
			sort_swap(list, node);
		}
	}
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * 
 * @list: list to be sorted
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *temp = (*list)->next;

	if (!list || !(*list) || !(*list)->next)
		return;
	while (temp)
	{
		sort_swap(list, temp);
		temp = temp->next;
	}
}
