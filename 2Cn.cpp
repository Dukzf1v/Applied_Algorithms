#include <iostream>
using namespace std;

int n;
int a[100];
int x[100];
int appear[100];

void input(){
    cin >> n;
    for(int i=0;i<n;i++) cin >> a[i];
}

int check(int v){
    
    if(appear[v] == 1) return 0;
    return 1;
}

void solution(){
    cout << "(" << x[0] << ", " << x[1] << ")" << endl;
}

void Try(int k){
    for(int v = 0; v < n; v++){
        if(check(v)){
            if(k==0||a[v]>x[k-1]){
                x[k] = a[v];
                appear[v] = 1;
                if(k==1) solution();
                Try(k+1);
                appear[v] = 0;
            }
        }
    }
}

int main(){
    input();
    Try(0);
}