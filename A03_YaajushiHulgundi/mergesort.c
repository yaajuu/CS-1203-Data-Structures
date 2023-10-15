#include <stdio.h>

int arr[] = {2, 46, 5, 89, 300, 56, 77, 29, 1};
int length = sizeof(arr) / sizeof(arr[0]);

void merge(int arr[], int beg, int mid, int last) {  //merges the sorted mini arrays
    int firsthalf = mid - beg + 1;
    int secondhalf = last - mid; //calculate how long each of the smaller arrays are

    int left[firsthalf], right[secondhalf]; //gives the two subarrays names as left and right

    for (int i = 0; i < firsthalf; i++)
        left[i] = arr[beg + i];
    for (int j = 0; j < secondhalf; j++)
        right[j] = arr[mid + 1 + j]; //copies sub arrays into left and right 

    int i, j, k;
    i = 0;
    j = 0;
    k = beg; //k is initialised to be start of the subarrays
 
    while (i < firsthalf && j < secondhalf) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++; //loop compares left and right elements and copies the smaller one into the original array
    }

    while (i < firsthalf) {
        arr[k] = left[i];
        i++;
        k++; //goes through the rest of the elements in the left subarray
    }

    while (j < secondhalf) {
        arr[k] = right[j];
        j++;
        k++;//goes through the rest of the elements in the right subarray
    }
}

void mergeSort(int arr[], int beg, int last) {
    if (beg < last) {
        int mid = beg + (last - beg) / 2; //finds middle of arr and divides it into left and right smaller arrays
        mergeSort(arr, beg, mid); //repeats this for the first smaller array and divides that
        mergeSort(arr, mid + 1, last); //repeats this for the second smaller array and divides that
        merge(arr, beg, mid, last); //merges the sorted subarrays
    }
}

int main() {
    printf("the unsorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
        
    }
    printf("\n");

    mergeSort(arr, 0, length - 1);

    printf("sorted array using merge sort is: ");
    for (int i = 0; i < length; i++)
        printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
