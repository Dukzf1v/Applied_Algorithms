#include<bits/stdc++.h>
using namespace std;
const int N = 10005;
int n, a[N], dp[N][N];

void inp(){
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
}

int proc(){
	for(int i = 0; i < n; i++){
		dp[i][i] = 1;
	}
	for(int len = 2; len <= n; len++){
		for(int i = 0; i < n; i++){
			int j = i + len - 1;
			if(a[i]==a[j]){
				dp[i][j] = dp[i+1][j-1]+2;
			} else {
				dp[i][j] = max(dp[i+1][j],dp[i][j-1]);
			}
		}
	}
	return dp[0][n-1];
}

int main(){
	inp();
	int result = proc();
	cout << result;
	return 0;
}