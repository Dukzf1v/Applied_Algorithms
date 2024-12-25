#include <bits/stdc++.h>
using namespace std;

stack<int> C; 
queue<int> H; 
int n; 
string input; 

void inp() {
    cin >> n;
    vector<int> temp(n); 

    for (int i = 0; i < n; i++) {
        cin >> temp[i];
    }

    for (int i = n - 1; i >= 0; i--) {
        C.push(temp[i]);
    }

    cin >> input; 
}

void proc() {
    for (char c : input) {
        if (c == 'C') { 
            if (!C.empty()) {
                int mem = C.top();
                C.pop();
                H.push(mem);
            }
        } else if (c == 'H') { 
            if (!H.empty()) {
                int mem = H.front();
                H.pop();
                C.push(mem);
            }
        }
    }

    vector<int> result;
    while (!C.empty()) {
        result.push_back(C.top());
        C.pop();
    }

    reverse(result.begin(), result.end()); 
    for (int x : result) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    inp(); 
    proc(); 
    return 0;
}
