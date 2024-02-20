#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

int *sortm(int *l_arr, size_t l_size, int *r_arr, size_t r_size,int *array, size_t size) {
  size_t i = 0, j = 0, k=0;
    size_t m_size = l_size + r_size;
    int *m_arr = (int *)malloc(m_size * sizeof(int));
    printf("Merging...\n");
	printf("[left]: ");
	print_array(l_arr, l_size);
	printf("[right]: ");
	print_array(r_arr, r_size);
    
    if (m_arr == NULL) {
        
    }

    
    while (i < l_size && j < r_size) {
        if (l_arr[i] < r_arr[j]) {
            array[k++] = l_arr[i++];
        } else {
            array[k++] = r_arr[j++];
        }
    }
  

    
   while (i < l_size) {
        array[k++] = l_arr[i++];
    }
    while (j < r_size) {
        array[k++] = r_arr[j++];
    }

    printf("[Done]: ");
	print_array(array, size);
    return array;
}

void merge_sort(int *array, size_t size) {
   size_t j, i;
  
   if (!array)
		return;

	if (size < 2)
		return;
    
    if (size > 1) {
        size_t l_size = size / 2;
        size_t r_size = size - l_size;

        int *l_arr = (int *)malloc(l_size * sizeof(int));
        int *r_arr = (int *)malloc(r_size * sizeof(int));

        for (i = 0; i < l_size; i++) {
            l_arr[i] = array[i];
        }

        for (j = 0; j < r_size; j++) {
            r_arr[j] = array[l_size + j];
        }

      

        merge_sort(l_arr, l_size);
        merge_sort(r_arr, r_size);

        sortm(l_arr, l_size, r_arr, r_size,array , size);
        printf("Merged Array: ");
        

        free(l_arr);
        free(r_arr);
        
    }
}
