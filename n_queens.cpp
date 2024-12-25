#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> results;
        vector<string> board(n, string(n, '.'));  
        vector<bool> cols(n, false), diag1(2 * n - 1, false), diag2(2 * n - 1, false);  
        backTrack(results, board, cols, diag1, diag2, n, 0); 
        return results;
    }

private:
    void backTrack(vector<vector<string>>& results, vector<string>& board, vector<bool>& cols, vector<bool>& diag1, vector<bool>& diag2, int n, int row) {
        if (row == n) {
            results.push_back(board); 
            return;
        }

        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row - col + n - 1] || diag2[row + col]) {
                continue;
            }

            board[row][col] = 'Q'; 
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = true; 

            backTrack(results, board, cols, diag1, diag2, n, row + 1);  

            board[row][col] = '.';  
            cols[col] = diag1[row - col + n - 1] = diag2[row + col] = false;  
        }
    }
};

int main() {
    Solution sol;
    int n = 4; 
    vector<vector<string>> results = sol.solveNQueens(n);

    for (const auto& board : results) {
        for (const auto& row : board) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
