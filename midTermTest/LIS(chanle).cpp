#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 100005;
int n;
int f1[MAX] = {0}; 
int f2[MAX] = {0}; 
int a[MAX];

void inp() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
}

void proc() {
    for(int i = 0; i < n; i++){
        if(a[i] % 2 == 0){
            f1[i] = 1;
        } else {
            f2[i] = 1;
        }
    }

    for (int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++){
            if(a[j]<=a[i]){
                if(a[i]%2==0 && a[j]%2==0){
                    f1[i] = f1[j] + 1;
                } else if(a[i]%2!=0 && a[j]%2!=0) {
                    f2[i] = f2[j] + 1;
                }
            }
        }
    }

    int max_even = *max_element(f1, f1 + n); 
    int max_odd = *max_element(f2, f2 + n); 
    int result = max(max_even, max_odd);

    cout << result;
}

int main() {
    inp();
    proc();
    return 0;
}
