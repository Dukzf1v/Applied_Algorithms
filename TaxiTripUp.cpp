#include <bits/stdc++.h>
using namespace std;

#define MAX_N 100

int N; 
int Q; 
int X[2*MAX_N + 1]; 
int q = 0; 
bool appear[2*MAX_N+1] = {0}; 

bool check(int v) {
    if (appear[v]) return false; 
    if (v <= N) { 
        if (q >= Q) return false; 
    } else { 
        if (!appear[v-N]) return false; 
    }
    return true;
}

void solution() {
    for (int i = 1; i <= 2*N; i++) 
        cout << X[i] << " ";
    cout << endl;
}

void TRY(int k) {
    for (int v = 1; v <= 2*N; v++) {
        if (check(v)) {
            X[k] = v;
            appear[v] = true;
            if (v <= N) q++; 
            else q--; 

            if (k == 2*N) solution(); 
            else TRY(k+1); 

            appear[v] = false; 
            if (v <= N) q--; 
            else q++;
        }
    }
}

int main() {
    N = 3; 
    Q = 2; 
    
    TRY(1); 
    return 0;
}
