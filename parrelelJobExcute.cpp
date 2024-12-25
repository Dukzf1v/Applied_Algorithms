#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;  
    vector<int> d(n); 

    for (int i = 0; i < n; i++) {
        cin >> d[i]; 
    }

    sort(d.begin(), d.end());

    int currentTime = 0; 
    int maxCompletionTime = 0; 

    for (int i = 0; i < n; i++) {
        currentTime =  d[i];  
        maxCompletionTime = currentTime;  
    }

    cout << maxCompletionTime << endl;

    return 0;
}
