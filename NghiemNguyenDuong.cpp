#include<iostream>
using namespace std;
int m;
int n;
int x[100];
int T = 0;

int check(int v, int k){
    if(k<n) return 1;
    return T + v == m;
}

void solution(){
    for(int i = 1; i <= n; i++){
        cout << x[i] << " ";
    }
    cout << endl;
}

void Try(int k){
    for(int v = 1; v <= m - T - (n-k); v++){
        if(check(v,k)){
            x[k] = v;
            T += x[k];
            if(k == n) solution();
            else Try(k+1);
            T -= x[k];
        }
    }
}

int main(){
    m = 5;
    n = 3;
    Try(1);
}