#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solveSudoku(vector<vector<char>>& board){
        backTrack(board, 0,0);
    }
private:
    bool check(vector<vector<char>>& board, int x, int y, char value){
        for(size_t i = 0; i < 9; i++){
            if(board[x][i] == value){
                return false;
            }
        }
        for(size_t j = 0; j < 9; j++){
            if(board[j][y] == value){
                return false;
            }
        }
        int org_x = x - x % 3;
        int org_y = y - y % 3;
        for(size_t i = org_x; i < 3 + org_x; i++){
            for(size_t j = org_y; j < 3 + org_y; j++){
                if(board[i][j] == value){
                    return false;
                }
            }
        }
        return true;
    }
    bool backTrack(vector<vector<char>>& board, int x, int y){
        if(x == 9){
            return true;
        }
        if(y == 9){
            return backTrack(board, x+1, 0);
            
        }
        if(board[x][y] != '.'){
            return backTrack(board, x, y + 1);
        }
        for(int i = '1'; i <= '9'; i++){
            if(check(board, x, y, i)){
                board[x][y] = i;
                if(backTrack(board, x, y+1)){
                    return true;
                }
                board[x][y] = '.';
            }
        }
    return false;
    }
};

int main() {
    Solution solution;

    vector<vector<char>> board = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '4', '1', '9', '5', '.', '.', '.'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };
    solution.solveSudoku(board);

    cout << "Sudoku after solving:\n";
    for (const auto& row : board) {
        for (char ch : row) {
            cout << ch << " ";
        }
        cout << endl;
    }

    return 0;
}