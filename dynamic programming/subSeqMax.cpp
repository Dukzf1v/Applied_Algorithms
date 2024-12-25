#include <iostream>
using namespace std;

#define INF 1e9
#define MAX 100000000
int n;
int a[100];

void input(){
    cin >> n;
    for(int i = 0; i < n; i++) cin >> a[i];
}

int PL(int l, int r){
    int rs = -INF;
    int s = 0;
    for(int i = r; i >= l; i--){
        s += a[i];
        rs = max(rs, s);
    }
    return rs;
}

int PR(int l, int r){
    int rs = -INF;
    int s = 0;
    for(int i = l; i <= r; i++){
        s += a[i];
        rs = max(rs, s);
    }
    return rs;
}

int P(int l, int r){
    if(r==l) return a[l];
    int m = (l+r)/2;
    return max(max(P(l,m),P(m+1,r)), PL(l,m)+PR(m+1,r));
}

void solve(){
    cout << P(0,n-1);
}

int main(){
    input();
    solve();
    return 0;
}