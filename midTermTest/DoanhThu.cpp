#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, S;
    cin >> n >> S;
    vector<int> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
    }

    int start = 0, currentSum = 0, maxLength = 0;

    for (int i = 0; i < n; i++) {
        currentSum += a[i]; 

        while (currentSum > S) {
            maxLength = max(maxLength, i - start + 1); 
            currentSum -= a[start];
            start++;
        }
    }

    cout << maxLength << endl; 
    return 0;
}
