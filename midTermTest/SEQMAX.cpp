#include<bits/stdc++.h>
using namespace std;
int n, k;
int a[100005];

void inp(){
    cin >> n >> k;
    for(int i=0;i<n;i++){
        cin >> a[i];
    }
}

double aver(int i, int j){
    double sum = 0.0;
    for(int k = i; k <= j; k++){
        sum += a[k];
    }
    double average = sum / (j-i+1);
    return average;
}

void proc(){
    double res;
    for(int i = 0; i < n; i++){
        for(int j = i; j < n; j++){
            if(j-i+1>=k){
                res = max(res, aver(i,j));
            }
        }
    }
    cout << setprecision(5) << res;
}

int main(){
    inp();
    proc();
    return 0;
}