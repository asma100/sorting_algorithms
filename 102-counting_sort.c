#include <stdio.h>
#include <stdlib.h>
#include "sort.h"
/**
 * duplicate_array - type of sorting
 * @original_array: input
 * @size:size of input
 * Return: copy of original array
 */
int *duplicate_array(int *original_array, int size)
{
int *duplicate_array = (int *)malloc(size * sizeof(int));
int i;
for (i = 0; i < size; i++)
{
duplicate_array[i] = original_array[i];
}
return (duplicate_array);
free(duplicate_array);


}
/**
 * counting_sort - type of sorting
 * @array: input
 * @size:size of input
 * Return: void
 */
void counting_sort(int *array, size_t size)
{
int c, x, y, b, j, k;
size_t i, l;
int max = array[0];
int *coun_arr;
int *cp_arr;
for (i = 0; i < size; i++)
{
if (array[i] > max)
max = array[i];
}
coun_arr = malloc((max + 1) * sizeof(int));
for (j = 0; j < max + 1; j++)
coun_arr[j] = 0;
for (k = 0; k < max + 1; k++)
{
for (l = 0; l < size; l++)
{
if (k == array[l])
{
coun_arr[k] = coun_arr[k] + 1;
}
}
}
for (x = 1; x < max + 1; x++)
{
coun_arr[x] = coun_arr[x] + coun_arr[x - 1];
}
print_array(coun_arr, max + 1);
cp_arr = duplicate_array(array, size);
for (y = size - 1; y >= 0; y--)
{
c = cp_arr[y];
b = coun_arr[c];
array[b - 1] = c;
coun_arr[c]--;
}
free(coun_arr); 
}
