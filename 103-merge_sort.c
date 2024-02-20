#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * sortm - Merge
 * @l_arr: Left array
 * @l_size: Size of the left array
 * @r_arr: Right array
 * @r_size: Size of the right array
 * @array: Output array to store merged result
 * @size: Size of the output array
 *
 * Return: Pointer to the merged array
 */
int *sortm(int *l_arr, size_t l_size,
	   int *r_arr, size_t r_size, int *array, size_t size)
{
size_t i = 0, j = 0, k = 0;
while (i < l_size && j < r_size)
{
if (l_arr[i] < r_arr[j])
array[k++] = l_arr[i++];
else
array[k++] = r_arr[j++];
}
while (i < l_size)
array[k++] = l_arr[i++];
while (j < r_size)
array[k++] = r_arr[j++];
printf("[Done]: ");
print_array(array, size);
return (array);
}
/**
 * merge_sort - Sorts an array
 * @array: Array to be sorted
 * @size: Size of the array
 */
void merge_sort(int *array, size_t size)
{
size_t j, i;
size_t l_size = size / 2;
size_t r_size = size - l_size;
int *l_arr = (int *)malloc(l_size * sizeof(int));
int *r_arr = (int *)malloc(r_size * sizeof(int));
if (!array || size < 2)
return;
for (i = 0; i < l_size; i++)
l_arr[i] = array[i];
for (j = 0; j < r_size; j++)
r_arr[j] = array[l_size + j];
merge_sort(l_arr, l_size);
merge_sort(r_arr, r_size);
sortm(l_arr, l_size, r_arr, r_size, array, size);
printf("Merged Array: ");
free(l_arr);
free(r_arr);
}
