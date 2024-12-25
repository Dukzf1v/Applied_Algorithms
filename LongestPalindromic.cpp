#include <iostream>
#include <vector>
using namespace std;

#define MAX 10000
vector<vector<int>> dp(MAX, vector<int>(MAX, -1)); 
string str;
int maxLen = 1;

bool isPal(int i, int j) {
    if (dp[i][j] != -1) { 
        return dp[i][j];
    }
    if (i == j) { 
        dp[i][j] = 1;
        return true;
    }
    if (i + 1 == j) { 
        if (str[i] == str[j]) {
            dp[i][j] = 1;
            return true;
        }
        dp[i][j] = 0;
        return false;
    }
    if (str[i] == str[j] && isPal(i + 1, j - 1)) {
        dp[i][j] = 1;
        return true;
    }
    dp[i][j] = 0;
    return false;
}

int longestPalCal(int i, int j) {
    if (i >= j) { 
        return maxLen;
    }
    if (isPal(i, j)) {
        maxLen = max(maxLen, j - i + 1);
    } else {
        longestPalCal(i + 1, j); 
        longestPalCal(i, j - 1); 
    }
    return maxLen;
}

int main() {
    cin >> str; 
    int n = str.length();
    cout << longestPalCal(0, n - 1) << endl; 
    return 0;
}
