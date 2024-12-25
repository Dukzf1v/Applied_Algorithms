#include <iostream>
using namespace std;

int n;

void InsertionSort(int x[]){
    for(int i = 0; i < n; i++){
        int key = x[i];
        int j = i - 1;
        while(j >= 0 && key < x[j]){
            x[j+1] = x[j];
            j--;
        }
        x[j+1] = key;
    }
}

int main(){
    n = 10;  // Size of the array
    int x[] = {-3, -2, 5, 7, 1, 4, 5, -5, -3, -7};
    InsertionSort(x);
    for(int i = 0; i < n; i++){
        cout << x[i] << " ";
    }
    return 0;
}
