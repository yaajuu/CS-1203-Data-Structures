#include <stdio.h>

#define TRUE 1
#define FALSE 0

int arr1[] = {2, 46, 5, 89, 300, 56, 77, 29, 1};
int length = sizeof(arr1) / sizeof(arr1[0]); //calculates length of array

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; //swap function to swap two elements
}
void bubblesort(int arr[], int n) { //takes in an array and the length of an array
    int i, j, x; //initialises 3 variables - i and j are loop counters and x is 
    for( i = 0; i < n - 1 ; i++ ) {//outer loop that goes in the array from the first to the second last element
        int swapped = FALSE; //checks whether swaps have been made
        for( j = 0; j < n - i - 1 ; j++ ) { //inner loop that goes from the first elemenet to the last element before the sorted portion of the array
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]); //swaps current element with next one if the next one is smaller
                swapped = TRUE; //shows a swap has been made
            }
        }
        if (!swapped) { //if there are no more swaps left then its fully sorted
            break;
        }
    }
}

int main() {
    printf("the unsorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr1[i]);
        
    }
    printf("\n");

    bubblesort(arr1, length); 
    printf("the sorted array using bubble sort: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr1[i]);
    }
}
