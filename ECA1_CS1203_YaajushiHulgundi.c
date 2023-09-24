#include <stdio.h>

int n = 8; // i am setting n to 8 here itself because if it runs and provides the right output for n = 8, it'll work for all values upto 8.

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp; //swap function we did in class because it swaps the order of elemets so we can get different orders for permutations. 
}

int nextperm(int* arr, int n) { //this function generates the next permutation based off the previous one. The first permutation will be the array of the numbers leading up to 8. 
    int i, j, k;
    int mobile, temp; 

    i = n - 1; //using the last element in the array
    while (i >= 0 && arr[i] >= arr[i + 1]) 
        i--; //i decrements 

    if (i < 0)
        return 0; //this is if i becomes less than 0 so it means that it has no permutations left to display so the program breaks

    j = n - 1; // j starts from the last element of the array
    while (arr[j] <= arr[i])
        j--; 

    swap(&arr[i], &arr[j]); // swaps i and j

    int left = i + 1;
    int right = n - 1;
    while (left < right) {
        swap(&arr[left], &arr[right]);
        left++;
        right--; // reverses order of the elements that are on the right of i and this makes the next permutation. 
    }

    return 1;
}

int main() {
    

    int arr[n];
    for (int i = 1; i <= n; i++) {
        arr[i-1] = i; // gives an index to each element in th array
    }

    int length_of_array = sizeof(arr) / sizeof(arr[0]); //found this formula online to calculate length of array
    int j = 0; // show that j is the first element 
    
    for (j = 0; j < length_of_array; j++) {
        printf("%d ", arr[j]); //prints out first permutation
    }
    printf("\n"); //prints out a new line

    while (nextperm(arr, n)) {
        for (j = 0; j < length_of_array; j++) {
            printf("%d ", arr[j]); //prints out the first permutation and a new line and then the next permutation
        }
        printf("\n");
    }

    return 0;
}
