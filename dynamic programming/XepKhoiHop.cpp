#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 1001;
const int MAX_W = 20001;
long long dp[MAX_N][MAX_W];

struct Block {
    int weight;  
    int strength;  
    int value; 
};

Block a[MAX_N];

bool compare(Block a, Block b) {
    return a.strength + a.weight < b.strength + b.weight;  
}

int main() {
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> a[i].weight >> a[i].strength >> a[i].value;
    }

    sort(a, a + n, compare);

    memset(dp, 0, sizeof(dp));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= MAX_W; j++) {
            dp[i + 1][j] = dp[i][j];  
            if (j >= a[i].weight && j <= a[i].strength + a[i].weight) {
                dp[i + 1][j] = max(dp[i + 1][j], dp[i][j - a[i].weight] + a[i].value); 
            }
        }
    }

    long long result = 0;
    for (int j = 0; j <= MAX_W; j++) {
        result = max(result, dp[n][j]);
    }

    cout << result << endl;
    return 0;
}
