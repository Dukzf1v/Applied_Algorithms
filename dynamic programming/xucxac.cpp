#include<bits/stdc++.h>
using namespace std;
int f[1005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin>>n;
    f[0] = 1;
    for(int s=1;s<=n;s++){
        for(int j = 1; j <= 6; j++){
            if(j<=s){
                f[s] = f[s] + f[s-j];
            }
        }
    }
    cout << f[n];
    return 0;
}