#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> mem(n+1,-1);
        return result_dp(n,mem);
    }
    int result_dp(int n, vector<int>& mem){
        if(n<=1){
            return 1;
        }
        if(mem[n] != -1){
            return mem[n];
        }
        mem[n] = result_dp(n-1,mem) + result_dp(n-2,mem);
        return mem[n];
    }
};

int main() {
    Solution solution;
    int n = 5;
    cout << solution.climbStairs(n);
    return 0;
}
