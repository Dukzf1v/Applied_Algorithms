#include <bits/stdc++.h>
using namespace std;

void QuickSort(vector<int>& x, vector<int>& result) {
    if (x.size() <= 1) {
        // If the array has 1 or 0 elements, it is already sorted
        result.insert(result.end(), x.begin(), x.end());
        return;
    }

    int pivot = x[x.size() - 1]; // Use the last element as the pivot
    vector<int> s; // Elements smaller or equal to the pivot
    vector<int> b; // Elements larger than the pivot

    // Partition the array into two parts
    for (size_t i = 0; i < x.size() - 1; i++) {  // Changed 'int' to 'size_t'
        if (x[i] <= pivot) {
            s.push_back(x[i]);
        } else {
            b.push_back(x[i]);
        }
    }

    // Recursively sort the smaller and larger partitions
    QuickSort(s, result);
    result.push_back(pivot); // Add the pivot after the smaller elements
    QuickSort(b, result);
}

int main() {
    int n;
    cin >> n;
    
    vector<int> x(n);  // Input vector
    for (int i = 0; i < n; i++) {
        cin >> x[i];
    }

    vector<int> result; // Result vector
    QuickSort(x, result);

    // Output the sorted result
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
