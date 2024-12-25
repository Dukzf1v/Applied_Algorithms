#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void countingSort(vector<int>& arr) {
    int min_val = *min_element(arr.begin(), arr.end()); // Find the minimum value
    int max_val = *max_element(arr.begin(), arr.end()); // Find the maximum value

    // Range of numbers in the array
    int range = max_val - min_val + 1;

    // Create a count array of size equal to the range of numbers
    vector<int> count(range, 0);
    vector<int> output(arr.size());

    // Store the count of each element in the count array
    for (size_t i = 0; i < arr.size(); i++) {
        count[arr[i] - min_val]++;  // Shift values by subtracting min_val
    }

    // Modify the count array by adding the previous counts (cumulative count)
    for (size_t i = 1; i < count.size(); i++) {
        count[i] += count[i - 1];
    }

    // Build the output array
    for (int i = arr.size() - 1; i >= 0; i--) {
        output[--count[arr[i] - min_val]] = arr[i];  // Shift back by min_val
    }

    // Copy the sorted output array back into the original array
    for (size_t i = 0; i < arr.size(); i++) {
        arr[i] = output[i];
    }
}

int main() {
    vector<int> arr = {-5, -10, 0, -3, 8, 5, -1, 10};

    cout << "Original array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    countingSort(arr);

    cout << "Sorted array: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
