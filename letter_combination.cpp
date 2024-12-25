#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty()){
            return {};
        }
        map<char, string> digitsToLetters = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"},
        };
        vector<string> result;
        string temp;
        BackTracking(digits, digitsToLetters, result, 0, temp);
        return result;
    }
private:
    void BackTracking(string digits, map<char, string>& digitsToLetters, vector<string>& result, int index, string temp){
        if(index == digits.length()){
            result.push_back(temp);
            return;

        }
        char letter = digits[index];
        for(int i = 0; i < digitsToLetters[letter].length() ; i++){
            temp.push_back(digitsToLetters[letter][i]);
            BackTracking(digits, digitsToLetters, result, index + 1, temp);
            temp.pop_back();
        }
    }
};


int main(){
    Solution solution;
    string digits = "23";

    vector<string> combinations = solution.letterCombinations(digits);

    for (const string& combination : combinations){
        cout << combination << endl;
    }

    return 0;
}