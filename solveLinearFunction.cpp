#include <bits/stdc++.h>
using namespace std;

void backTrack(int a[], int n, int m, int k, int& count, int sum) {
    for (int i = 1; i <= (m - sum) / a[k]; i++) {
        sum += a[k] * i;
        if (sum > m) {
            sum -= a[k] * i;
            return;
        }
        if (k + 1 == n) {
            if (sum == m) {
                count++;
            }
        } else {
            backTrack(a, n, m, k + 1, count, sum);
        }
        sum -= a[k] * i;
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    int a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int count = 0;
    backTrack(a, n, m, 0, count, 0);
    cout << count;
    return 0;
}
