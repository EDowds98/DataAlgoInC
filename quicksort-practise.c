#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This function takes in an arbitary number of elements and inserts them into an array, 
 * then returns a pointer to the first element
*/
int arr_length = 10;
int sorted_arr[10];
int sorted_arr_index = 0;

int* user_input() {
    static int arr[10];

    for(int i = 0; i <= arr_length; i++) {
        scanf("%d", &arr[i]);
    }

    return arr;
}


void quicksort(int* arr, int arr_length) {
   
    printf("printing arr indices\tarr_length = %d\n", arr_length); 
    for(int i =0; i < arr_length; i++) {
        printf("%d ", arr[i]);
    }

    if(arr_length <= 1) {
        sorted_arr[sorted_arr_index] = *arr;
        sorted_arr_index++;
        for(int i = 0; i <= 10; i++) {
            printf("%d ", sorted_arr[i]);
        }
        printf("\n");

    } else {

    srand(time(0));

    // first select a random element to be the pivot
    int pivot = arr[rand() % arr_length];
    int* less_than, *equals, *more_than; // arrays for partition step (realloc will be used a lot here)
    less_than = equals = more_than = (int*)malloc(arr_length * sizeof(int));
    int less_than_count, equals_count, more_than_count; // keep track of where to add elements 
    less_than_count = equals_count = more_than_count = 0;

    printf("pivot is: %d\n", pivot);
    // then split the array into less than, equals, more than
    for(int i = 0; i <= arr_length; i++){
        if(*(arr+i) < pivot) {
            *(less_than + less_than_count) = *(arr+i);
            less_than_count++;
        } else if(*(arr+i) > pivot) {
            *(more_than + more_than_count) = *(arr+i);
            more_than_count++;
        } else {
            *(equals + equals_count) = *(arr+i);
            equals_count++;
        }
    }

    printf("used size of less than array: %d\nused size of equals array: %d\nused size of more than array: %d\n", less_than_count, equals_count, more_than_count);

    // now we reallocate memory to shrink the arrays
    if (less_than_count >= 1) {
        less_than = (int*) realloc(less_than, (less_than_count * sizeof(int)));
        printf("less than array shrank\n");
    }
    
    if(equals_count >= 1) {
        equals = (int*) realloc(less_than, (equals_count * sizeof(int)));
        printf("equals array shrank\n");
    }

    if(more_than_count >= 1) {
        more_than = (int*) realloc(less_than, (more_than_count * sizeof(int)));
        printf("more than array shrank\n");
    }

    // now the hard part: call this function recursively until there's only one number
    // then recombine (overwrite original array)

    // first we'll do the recursion for less_than
    // base case
        // TODO just gotta thinky
    
        quicksort(less_than, less_than_count); // the logic here is sus i think these should be split into different if statements or while > 0
        quicksort(equals, equals_count);
        quicksort(more_than, more_than_count);
    }
}

int main(void) {
    int *main_arr = user_input();
    quicksort(main_arr, arr_length);

    for(int i = 0; i <= arr_length; i++) {
        printf("%d ", *(main_arr+i));
    }
    printf("\n");
    return 0;
}