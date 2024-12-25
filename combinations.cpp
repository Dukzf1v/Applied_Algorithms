#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> path;
        vector<vector<int>> result;
        int start = 1;
        backTrack(result, path, n, k, start);
        return result;
    }
private:
    void backTrack( vector<vector<int>> &result, vector<int> &path, int n, int k, int start){
        if(path.size() == k){
            result.push_back(path);
            return;
        }
        for(int i = start; i <= n; i++){
            path.push_back(i);
            backTrack(result, path, n, k, i + 1);
            path.pop_back();
        }
    }
};

int main() {
    int n = 4, k = 2;
    Solution solution;
    vector<vector<int>> result = solution.combine(n, k);

    for (const auto& combination : result) {  // Duyệt qua các tổ hợp
        for (int num : combination) {
            cout << num << " ";  // In từng phần tử trong tổ hợp
        }
        cout << endl;
    }

    return 0;
}