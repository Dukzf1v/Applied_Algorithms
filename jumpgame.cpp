#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if(nums[0] == 0){
            if(nums.size() == 1){
                return true;
            }
            return false;
        }
        vector<bool> dp(n , false);
        dp[0] = true;
        for(int i = 0; i < n; i++){
            int maxReach = min(n-1, i + nums[i]);
            for(int j = i+1; j <= maxReach; j++){
                dp[j] = true;
            }
        }
        for(int i = 0; i < n; i++){
            if(dp[i] == false){
                return false;
            }
        }
        return true;
    }
};

/*
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxReach = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxReach) return false;
            maxReach = max(maxReach, i + nums[i]);
        }
        return true;
    }
};
*/

int main(){
    Solution solution;
    vector<int> nums = {0,2,3};
    bool result = solution.canJump(nums);
    cout << result ? "True" : "False";
    return 0;
}