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
 * lomuto_partition - partitions the array using Lomuto scheme
 * @array: array to be partitioned
 * @low: starting index of the partition
 * @high: ending index of the partition
 * @size: size of the array
 * Return: index of the pivot element
 */
int lomuto_partition(int *array, int low, int high, size_t size)
{
	int pivot = array[high];
	int i = low - 1, j;

	for (j = low; j <= high - 1; j++)
	{
		if (array[j] <= pivot) {
			i++;
			swap(&array[i], &array[j]);
		}
	}
	swap(&array[i + 1], &array[high]);
	print_array(array, size);
	return (i + 1);
}

/**
 * quicksort - sorts an array of integers in ascending order using quicksort
 * @array: array to be sorted
 * @low: starting index of the array
 * @high: ending index of the array
 * @size: size of the array
 */
void quicksort(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi = lomuto_partition(array, low, high, size);
		quicksort(array, low, pi - 1, size);
		quicksort(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - sorts an array of integers in ascending order using quicksort
 * @array: array to be sorted
 * @size: size of the array
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;
	quicksort(array, 0, size - 1, size);
}
