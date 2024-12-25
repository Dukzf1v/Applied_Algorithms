#include<bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    int bound; cin >> bound;
    int cnt = 0;
    int sum = 0;
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            sum += a[j];
        }
    }
    cout << cnt;
    return 0;
}