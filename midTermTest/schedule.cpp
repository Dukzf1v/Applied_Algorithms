#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> d(n);

    for (int i = 0; i < n; i++) {
        cin >> d[i];
    }

    sort(d.begin(), d.end(), greater<int>());

    int count = 0; 
    int i = 0, j = n - 1;

    while (i <= j) {
        int temp = 6; 
        temp -= d[i];
        i++;

        while (i <= j && temp >= d[j]) {
            temp -= d[j];
            j--;
        }
        count++;
    }

    cout << count << endl;
    return 0;
}
