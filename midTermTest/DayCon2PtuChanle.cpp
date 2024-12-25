#include<bits/stdc++.h>
using namespace std;
const int MAX = 100005;

int main(){
    int n; cin >> n;
    int a[n];
    for(int i =0; i < n; i++){
        cin >> a[i];
    }
    int result = *max_element(a, a+n);
    cout << result;
    return 0;
}
