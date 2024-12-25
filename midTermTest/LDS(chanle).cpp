#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100005;
int n;
int dp[MAX];
int a[MAX];

void inp(){
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
}

void proc(){
    dp[0] = 1; 
    for(int i = 1; i < n; i++){
        dp[i] = 1; 
        for(int j = 0; j < i; j++){
            if(a[i] < a[j] && (a[i] + a[j]) % 2 != 0){
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
    }

    int result = *max_element(dp, dp + n);
    cout << result << endl;
}

int main(){
    inp();
    proc();
    return 0;
}
