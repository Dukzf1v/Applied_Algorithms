#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        for(int i = 0; i <= n; i++){
            result[i] = __builtin_popcount(i);
        }
        return result;
    }
};
int main() {
    Solution solution;
    int n = 5;
    vector<int> result = solution.countBits(n);
    for(int i : result){
        cout << i << " ";
    }
    
    return 0;
}
