#include <iostream>
using namespace std;

int n;

void merge(int x[], int L[], int R[], int lsize, int rsize){
    int i = 0, j = 0, k = 0;  // Properly declare i, j, and k
    while(i < lsize && j < rsize){
        if(L[i] <= R[j]){  // Use L[] and R[] instead of left[] and right[]
            x[k++] = L[i++];
        } else {
            x[k++] = R[j++];
        }
    }
    while(i < lsize){
        x[k++] = L[i++];
    }
    while(j < rsize){
        x[k++] = R[j++];
    }
}

void mergeSort(int x[], int left, int right){
    if(left >= right){
        return;
    }
    int m = left + (right - left) / 2;
    
    // Recursively split and sort
    mergeSort(x, left, m);
    mergeSort(x, m + 1, right);
    
    // Define sizes for temporary arrays
    int lsize = m - left + 1;
    int rsize = right - m;
    
    // Create temporary arrays to hold the values
    int L[lsize], R[rsize];
    
    // Copy data to the temporary arrays
    for(int i = 0; i < lsize; i++){
        L[i] = x[left + i];
    }
    for(int i = 0; i < rsize; i++){
        R[i] = x[m + 1 + i];
    }

    // Merge the two halves back into the original array
    merge(x + left, L, R, lsize, rsize);  // Correct pointer arithmetic for merging
}

int main(){
    n = 10;  // Size of the array
    int x[] = {-3, -2, 5, 7, 1, 4, 5, -5, -3, -7};

    // Call mergeSort with the appropriate left and right bounds
    mergeSort(x, 0, n - 1);

    // Output the sorted array
    for(int i = 0; i < n; i++){
        cout << x[i] << " ";
    }
    
    return 0;
}
