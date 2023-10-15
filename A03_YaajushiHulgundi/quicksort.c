#include <stdio.h>

#define TRUE 1
#define FALSE 0

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; //swap function
}

int arr[] = {2, 46, 5, 89, 300, 56, 77, 29, 1};
int length = sizeof(arr) / sizeof(arr[0]);

int partition(int LEFT, int RIGHT, int pivot) { //defines a function that partitions the array based on a pivot
    int left_dir = LEFT - 1;
    int right_dir = RIGHT; //left and right directions based off of left and right side of the partition and points the direction towards the middle

    while (TRUE) {
        while (arr[++left_dir] < pivot) {
            // do nothing
        }

        while (right_dir > 0 && arr[--right_dir] > pivot) {
            // do nothing
        }

        if (left_dir >= right_dir) {
            break;
        } else {
            swap(&arr[left_dir], &arr[right_dir]); //swap is done if the left_dir is not greater or equal to the right_dir, so the loop terminates otherwise.
        }
    }

    swap(&arr[left_dir], &arr[RIGHT]);

    return left_dir; //pivot is swapped with the element at left_dir
}

void quicksort(int LEFT, int RIGHT) {
    if (RIGHT - LEFT <= 0) {
        return;
    } else {
        int pivot = arr[RIGHT]; //chooses the pivot element which initially is the rightmost element 
        int part = partition(LEFT, RIGHT, pivot);
        quicksort(LEFT, part - 1);
        quicksort(part + 1, RIGHT);  //applies quicksort function to the left and right mini arrays
    }
}

int main() {
    printf("the unsorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
        
    }
    printf("\n");
    quicksort(0, length - 1);

    printf("sorted array using mergesort: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
