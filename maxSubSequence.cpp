#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.empty()) return 0;
        int result = nums[0];
        vector<int>mark(nums.size());
        mark[0] = nums[0];
        for(int i = 1; i < nums.size(); i++){
            mark[i] = max(mark[i-1]+nums[i], nums[i]);
            result = max(mark[i], result);
        }
        return result;
    }
};

int main(){
    Solution solution;
    vector<int> nums = {5,4,-1,7,8};
    int result = solution.maxSubArray(nums);
    cout << result;
    return 0;
}