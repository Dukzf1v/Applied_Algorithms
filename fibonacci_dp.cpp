#include <iostream>
#include <map>
using namespace std;

map<int,int> mem;

int fib(int n){
    if(n<=2) return 1;

    if(mem.find(n) != mem.end())
        return mem[n];

    int res = fib(n-1) + fib(n-2);
    mem[n] = res;
    return res;
}

int main(){
    cout << fib(3);
    return 0;
}