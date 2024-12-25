#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int countWays(int n, int m, int d) {

    vector<vector<int>> f(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= m; i++) {
        f[i][i] = 1;
    }

    for (int i = 1; i <= n; ++i) { 
        for (int j = 1; j <= m; ++j) { 
            for (int k = max(1, j - d); k <= min(m, j + d); ++k) {
                f[i][j] += f[i-j][k];
                f[i][j] %= MOD;
            }
        }
    }

    int result = 0;
    for (int j = 1; j <= m; ++j) {
        result = (result + f[n][j]) % MOD;
    }

    return result;
}

int main() {
    int n, m, d;
    cin >> n >> m >> d;
    cout << countWays(n, m, d) << endl;
    return 0;
}
