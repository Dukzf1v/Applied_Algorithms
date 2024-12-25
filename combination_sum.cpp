#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> elements;
        int sum = 0;
        backTrack(candidates, target, result, sum, elements, 0);
        return result;
    }
private:
    void backTrack(vector<int>& candidates, int target, vector<vector<int>>& result, int sum, vector<int> elements, int k){
        if(sum == target){
            result.push_back(elements);
        }
        if (sum > target) return;
        for(int i = k; i < candidates.size(); i++){
            sum += candidates[i];
            elements.push_back(candidates[i]);
            backTrack(candidates, target, result, sum, elements, i);
            sum -= candidates[i];
            elements.pop_back();
        }
    }
};

int main(){ 
    Solution solution; 
    vector<int> candidates = {1,1,1};   
    int target = 5;
    vector<vector<int>> result = solution.combinationSum(candidates, target);
    for (size_t i = 0; i < result.size(); ++i) {
        for (size_t j = 0; j < result[i].size(); ++j) {
            std::cout << result[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}