#include <bits/stdc++.h>
using namespace std;

int dp[1005]={0};
int main(){
    int n, s;
    cin >> n >> s;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i];
    dp[0] = 1;
    for(int i = 0; i < n; i++){
        dp[a[i]] = 1;
        for(int j=s;j>=a[i];j--){
            if(dp[j-a[i]]==1) dp[j]=1;
        }
    }
    if(dp[s]==1) cout << "YES";
    else cout << "NO";
}