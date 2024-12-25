#include<bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    sort(a.begin(), a.end());
    int cnt = 1, num_pair = 0;
    for(int i = 0; i < n; i++){
        if(a[i] == a[i+1]){
            cnt++;
        }
        else{
            num_pair += cnt*(cnt-1)/2;
            cnt = 1;
        }
    }
    cout << num_pair;
}
