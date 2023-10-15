#include <stdio.h>

int arr1[] = {2, 46, 5, 89, 300, 56, 77, 29, 1};
int arr2[] = {700, 987, 476, 347, 274, 111, 221};
int length = sizeof(arr1) / sizeof(arr1[0]);

void insertionsort(int arr[], int n){
    
    int i, j, x;
    for( i = 1; i < n ; i++ ){ //starts from the second element in the index. 
        x = arr[i]; //temp value that holds value of the current element in the array
        j = i;
        
         

         while (j > 0 && arr[j-1] > x) {
            arr[j] = arr[j-1];
            j--; //decremenets backwards through the sorted part of the array to find the right position for the element
         }
        
        arr[j] = x; //places the current element in the right position
    }
}

int main() {
    printf("the unsorted array: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr1[i]);
        
    }
    printf("\n");

    
    insertionsort(arr1, length);

    printf("the sorted array using insertion sort : ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr1[i]);
    }

    
}
