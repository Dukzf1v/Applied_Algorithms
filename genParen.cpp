#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string path;
        backTrack(result, path, 0, 0, n);
        return result;
    }

private:
    void backTrack(vector<string>& result, string path, int open, int close, int n) {
        if (path.size() == 2 * n) {
            result.push_back(path);
            return;
        }
        if (open < n) {
            backTrack(result, path + "(", open + 1, close, n);
        }
        if (close < open) {
            backTrack(result, path + ")", open, close + 1, n);
        }
    }
};

int main() {
    Solution solution;
    int n = 3;
    vector<string> result = solution.generateParenthesis(n);

    for (const string& str : result) {
        cout << str << endl;
    }
    return 0;
}
