#include<bits/stdc++.h>
using namespace std;

int check(int distance, int c,  vector<int> &a, int n){
    int ls = 1;
    int last = a[1];
    for(int i = 2; i < n; i++){
        if(a[i] - last >= distance){
            ls++;
            last = a[i];
            if(ls >= c) return 1;
        }
    }
    return 0;
}

int maxDistance(vector<int> &a, int n, int c){
    int l = 0;
    int r = a[n]-a[1];
    while(l <= r){
        int mid = (l+r)/2;
        if(check(mid, c, a, n)) l = mid + 1;
        else r = mid - 1;
    }
    return r;
}

int main(){
    int t; cin >> t;
    for(int i = 0; i < t; i++){
        int n,c;
        cin >> n >> c;
        vector<int> a(n+1);
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        sort(a.begin(),a.end());
        int result = maxDistance(a,n,c);
        cout << result << "\n";
    }
    return 0;
}