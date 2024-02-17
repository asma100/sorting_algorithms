#include "sort.h"

/**
 * swap - swaps two integers
 * @a: pointer to the first integer
 * @b: pointer to the second integer
 */
void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * sort_swap - does an inseration style swaping with a given
 * gap length between each step
 *
 * @interval: step between each element
 * @array: array of elements to sort
 * @index: index of element to start at
*/

void sort_swap(int interval, int *array, int index)
{
	if (index - interval >= 0)
	{
		if (array[index] < array[index - interval])
			swap(array + index, array + index - interval);
		sort_swap(interval, array, (index - interval));
	}
}

/**
 * shell_sort - sorts an array of integers in ascending order using the
 * Shell sort algorithm, using the Knuth sequence
 *
 * @array: array to be sorted
 * @size: size of the given array
*/

void shell_sort(int *array, size_t size)
{
	int i, j;

	if (size == 0 || !*array)
		return;
	for (i = 0; i <= (int)size; i = i * 3 + 1)
		;
	i = (i - 1) / 3;
	while (i > 0)
	{
		for (j = 0; j < (int)size; j++)
		{
			if (j + i <= (int)size)
			{
				if (array[j] > array[j + i])
				{
					swap(array + j, array + j + i);
					sort_swap(i, array, j);
				}
			}
		}
		print_array(array, size);
		i = (i - 1) / 3;
	}
}
