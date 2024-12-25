#include <bits/stdc++.h>
using namespace std;

int dp[1005][1005];
void solve(string str1, string str2){
    memset(dp,0,sizeof(dp));
    int res = 0;
    for(int i=1;i<=str1.size();i++){
        for(int j=1;j<=str2.size();j++){
            if(str1[i-1]==str2[j-1]&&i!=j){
                dp[i][j] = dp[i-1][j-1]+1;
            } else {
                dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
            res = max(res,dp[i][j]);
        }
    }
    cout << res << "\n";
}

int main(){
    int n; cin >> n;
    for(int i=0;i<n;i++){
        string str1, str2;
        cin >> str1 >> str2;
        solve(str1,str2);
    }
    return 0;
}