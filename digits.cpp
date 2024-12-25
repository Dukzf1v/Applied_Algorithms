#include<iostream>
using namespace std;

int x[7]; // X[0] = I, X[1] = C, X[2] = T, X[4] = H, X[5] = U, X[6] = S, X[3] = K
int appear[10];
int count;
int N;

int check(int v){
    if(appear[v]) return 0;
    return 1;
}

int cal(int x[]){
    int ICT = x[0] * 100 + x[1] * 10 + x[2];
    int K62 = x[3] * 100 + 62;
    int HUST = x[4] * 1000 + x[5] * 100 + x[6] * 10 + x[2];
    int result = ICT - K62 + HUST;
    return result;
}

void Try(int k){
    for(int v = 1; v <= 9; v++){
        if(check(v)){
            x[k] = v;
            appear[v] = 1;
            if(k==6){
                int result = cal(x);
                if(result == N) count++;
            } else Try(k+1);
            appear[v] = 0;
            
        }
    }
}

int main(){
    N = 1234;
    count = 0;
    Try(0);
    cout << count << endl;
}