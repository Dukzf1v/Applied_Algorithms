#include <iostream>
using namespace std;

int n;

void BubbleSort(int arr[], int n) {
    int flag = 1;
    int temp;  // Temporary variable for swapping
    while (flag) {
        flag = 0;
        for (int i = 1; i < n; i++) {
            if (arr[i - 1] > arr[i]) {  // Sorting in descending order
                flag = 1;
                // Swap the elements
                temp = arr[i];
                arr[i] = arr[i - 1];
                arr[i - 1] = temp;
            }
        }
    }
    // Print the sorted array
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int arr[] = {-3, -2, 5, 7, 1, 4, 5, -5, -3, -7};  // Correct initialization
    n = sizeof(arr) / sizeof(arr[0]);  // Automatically determine the size of the array
    BubbleSort(arr, n);
    return 0;
}
