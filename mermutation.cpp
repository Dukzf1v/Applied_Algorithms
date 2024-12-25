#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<int> visited(nums.size(), 0);
        sort(nums.begin(),nums.end());
        backTrack(result, path, nums, visited);
        return result;
    }
    void backTrack(vector<vector<int>> &result, vector<int> &path, vector<int> &nums, vector<int> &visited){
        if(path.size() == nums.size()){
            result.push_back(path);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            if(visited[i] == 1 || (i > 0 && nums[i] == nums[i-1] && visited[i-1] == 0)){
                continue;
            }
            path.push_back(nums[i]);
            visited[i] = 1;
            backTrack(result, path, nums, visited);
            path.pop_back();
            visited[i] = 0;
        }
    }
};

int main(){
    Solution sol;
    vector<int> nums = {1,1,2};
    vector<vector<int>> result = sol.permuteUnique(nums);
    for(const auto &path : result){
        for(const auto &row : path){
            cout << row << " ";
        }
        cout << endl;
    }
    return 0;
}