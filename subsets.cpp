#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        int count = 0, start = 0;
        vector<vector<int>> result;
        vector<int> path;
        backTrack(result, path, nums, start);
        return result;
    }
    void backTrack(vector<vector<int>> &result, vector<int> &path, vector<int> &nums, int start){
        result.push_back(path);
        for(int i = start; i < nums.size(); i++){
            path.push_back(nums[i]);
            backTrack(result, path, nums, i+1);
            path.pop_back();
        }
    }
};

int main(){
    vector<int> nums = {1,2,3};
    Solution sol;
    vector<vector<int>> result = sol.subsets(nums);
    for (const auto& path : result) { 
        for (int num : path) {
            cout << num << " ";  
        }
        cout << endl;
    }
    return 0;
}