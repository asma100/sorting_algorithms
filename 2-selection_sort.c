#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * selection_sort - type of sorting
 * @array: input
 * @size:size of input
 * Return: void
 */
void selection_sort(int *array, size_t size)
{
size_t i;
size_t j;
size_t temp;
int min;
size_t index;
if (array == NULL)
return;
for (i = 0; i < size; i++)
{
min = array[i];
for (j = i + 1; j < size; j++)
{
if (array[j] < min)
{
min = array[j];
index = j;
}
}
if (i != index)
{
temp = array[i];
array[i] = array[index];
array[index] = temp;
print_array(array, size);
}
}
}
