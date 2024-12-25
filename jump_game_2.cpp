#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        if (nums.size() == 1) return 0;
        int jumps = 0;
        int currEnd = 0;
        int Farest = 0;

        for(int i = 0; i < nums.size(); i++){
            Farest = max(Farest, i + nums[i]);
            if(i == currEnd){
                jumps++;
                currEnd = Farest;
            }
            if(currEnd >= nums.size() - 1){
                return jumps;
                break;
            }
        }
        return jumps;
    }
};

int main(){
    Solution sol;
    vector<int> nums = {2,3,1,1,4};
    int result = sol.jump(nums);
    cout << result;
    return 0;
}