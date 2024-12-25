#include <bits/stdc++.h>
using namespace std;

const int N = 1e4 + 5; 
int a[] = {3, -2, 5, -1, 4}; 
bool mark[N];           
map<int, int> mem;         

int maxSub(int i) {
    if (i == 0) return a[0]; 
    if (mark[i]) return mem[i]; 

    int res = max(a[i], a[i] + maxSub(i - 1));
    mark[i] = true; 
    mem[i] = res;  
    return res;
}

int main() {
    memset(mark, 0, sizeof(mark)); 
    int n = sizeof(a) / sizeof(a[0]); 
    cout << maxSub(n - 1) << endl; 
    return 0;
}
