#include "sort.h"

/**
  * sort_swap - Swap two nodes of a doubly linked list
  * @list: The double linked lists that contains the nodes
  * @node: The node to swap with the next node
  *
  * Return: Nothing!
  */
void sort_swap(listint_t **list, listint_t *node)
{
	node->next->prev = node->prev;

	if (node->next->prev)
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
  * list_lengt - Counts the number of elements in a doubly linked list
  * @h: The double linked list to count
  *
  * Return: Number of elements in the doubly linked list
  */
listint_t *list_lengt(listint_t *h)
{
	listint_t *temp = h;

	while (temp->next != NULL)
		temp = temp->next;

	return (temp);
}

/**
  * cocktail_sort_list - Sorts a doubly linked list
  * of integers in ascending order using the
  * Cocktail Shaker sort algorithm.
  * @list: The doubly linked list to apply the cocktail sort
  *
  * Return: Nothing!
  */
void cocktail_sort_list(listint_t **list)
{
	listint_t *temp = NULL, *low = NULL, *high = NULL;
	int direction = INCREMENT;

	if (!list || !(*list) || !(*list)->next)
		return;

	temp = *list;
	low = temp;
	high = list_lengt(*list);

	while (low != high)
	{
		if (temp->n == temp->next->n)
			break;
		else if (temp->n > temp->next->n && direction == INCREMENT)
			sort_swap(list, temp), print_list(*list);
		else if (temp->next->n < temp->n && direction == DECREMENT)
			sort_swap(list, temp), temp = temp->prev, print_list(*list);
		else if (direction == INCREMENT)
			temp = temp->next;
		else if (direction == DECREMENT)
			temp = temp->prev;

		if (direction == DECREMENT && temp->next == low)
		{
			direction = INCREMENT;
			temp = temp->next;
		}

		if (direction == INCREMENT && temp->prev == high)
		{
			high = high->prev;
			direction = DECREMENT;
			temp = temp->prev;
		}
	}
}
