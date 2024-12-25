#include <bits/stdc++.h>
using namespace std;

int dp[1005] = {1};
int res = 1;

void solve(int a[], int n){
    for(int i=0;i<=n;i++){
        for(int j=0;j<i;j++){
            if(a[j]<a[i]){
                dp[i] = max(dp[i],dp[j]+1);
            } 
        }
        res = max(res,dp[i]);
    }
}

int main(){
    int n; cin >> n;
    int a[n];
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
    solve(a,n);
    cout << res;
    return 0;
}