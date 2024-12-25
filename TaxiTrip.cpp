#include <iostream>
using namespace std;

int n;
int x[100];
int appear[100];

int check(int v){
    return appear[v] == 0;
}

void solution(){
    for(int i=1; i<=n; i++){
        cout << x[i] << " " << x[i] + n << " ";
        cout << endl;
    }
    cout << "---" << endl;
}

void Try(int k){
    for(int v = 1; v<=n; v++){
        if(check(v)){
            x[k] = v;
            appear[v] = 1;
            if(k==n) solution();
            else Try(k+1);
            appear[v] = 0;
        }
    }
}

int main(){
    n = 3;
    Try(1);
    return 0;
}