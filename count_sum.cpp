#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int combinationSum(vector<int>& coeff, int target) {
        int count = 0;
        backTrack(coeff, target, count, 0, 0);
        return count;
    }
private:
    void backTrack(vector<int>& coeff, int target, int& count, int sum, int k) {
        if (sum == target) {
            count++;
            return;
        }
        if (sum > target) return;

        for (int i = k; i < coeff.size(); i++) {
            sum += coeff[i]; 
            backTrack(coeff, target, count, sum, i); 
            sum -= coeff[i]; 
        }
    }
};

int main() { 
    Solution solution; 
    int n, target;
    cin >> n >> target; 
    vector<int> coeff(n); 
    
    for (int i = 0; i < n; ++i) {
        cin >> coeff[i];
    }

    int result = solution.combinationSum(coeff, target);
    cout << result << endl;
    return 0;
}
