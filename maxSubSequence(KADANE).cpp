#include <iostream>
using namespace std;

int findMaxSub(int arr[], int n) {
    if (n == 0) return 0; 

    int max_sum = arr[0]; 
    int current_sum = arr[0]; 

    for (int i = 1; i < n; i++) {
        current_sum = max(arr[i], current_sum + arr[i]);
        max_sum = max(max_sum, current_sum);
    }

    return max_sum;
}

int main() {
    int n;
    cin >> n;

    int arr[100];
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int result = findMaxSub(arr, n);
    cout << result << endl;

    return 0;
}
