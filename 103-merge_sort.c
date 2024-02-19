#include <stdio.h>
#include <stdlib.h>

void print_array(const int *array, size_t size) {
    size_t i = 0;

    while (i < size) {
        if (i > 0)
            printf(", ");
        printf("%d", array[i]);
        ++i;
    }
    printf("\n");
}

int *merge(int *l_arr, size_t l_size, int *r_arr, size_t r_size,int *array, size_t size) {
    int i = 0, j = 0, k = 0;
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

void divid(int *array, size_t size) {
   
   int *k;
   if (!array)
		return;

	if (size < 2)
		return;
    
    if (size > 1) {
        size_t l_size = size / 2;
        size_t r_size = size - l_size;

        int *l_arr = (int *)malloc(l_size * sizeof(int));
        int *r_arr = (int *)malloc(r_size * sizeof(int));

        for (size_t i = 0; i < l_size; i++) {
            l_arr[i] = array[i];
        }

        for (size_t j = 0; j < r_size; j++) {
            r_arr[j] = array[l_size + j];
        }

      

        divid(l_arr, l_size);
        divid(r_arr, r_size);

        k = merge(l_arr, l_size, r_arr, r_size,array , size);
        printf("Merged Array: ");
        

        free(l_arr);
        free(r_arr);
        
    }
}

int main(void) {
       int array[] = {19, 48, 99, 71, 13, 52, 96, 73, 86, 7};
    size_t n = sizeof(array) / sizeof(array[0]);

    print_array(array, n);
    printf("\n");
    divid(array, n);
    printf("\n");
    print_array(array, n);
    return (0);

    return 0;
}
