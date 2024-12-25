#include <bits/stdc++.h>
using namespace std;

const int N = 1e6+2;
int n;
long long S[N], f[2], res = -1e18, a[N];

void inp(){
    cin >> n;
    for(int i=1;i<=n;i++) cin >> a[i];
}

void proc(){
    int tmp;
    for(int i=1;i<=n;i++) S[i] = S[i-1] + a[i];
    f[1] = 1e18;
    for(int i=1;i<=n;i++){
        tmp = abs(S[i]) % 2;
        if(f[tmp] != 1e18) res = max(res, S[i]-f[tmp]);
        f[tmp] = min(f[tmp],S[i]);
    }
    if(res==-1e18) cout << "NOT_FOUND";
    else cout << res;
}

int main(){
    inp();
    proc();
    return 0;
}