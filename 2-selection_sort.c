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
int i;
int j;
int temp;
int min;
int index;
for (i = 0; i < size - 1; i++)
{
min = array[i];
for (j = i; j < size; j++)
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
