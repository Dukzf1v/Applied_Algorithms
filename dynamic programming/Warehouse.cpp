#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1005;
const int MAXT = 105;

int n, T, D;
int a[MAXN], t[MAXN];
int f[MAXN][MAXT];

void solve() {
    memset(f, 0, sizeof(f));

    int res = 0;

    for (int i = 1; i <= n; i++) {
        for (int k = T; k >= t[i]; k--) {
            for (int j = max(1, i - D); j < i; j++) {
                f[i][k] = max(f[i][k], f[j][k - t[i]] + a[i]);
            }
            res = max(res, f[i][k]);
        }
    }

    cout << res << "\n";
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> T >> D;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int i = 1; i <= n; i++) cin >> t[i];

    solve(); 
    return 0;
}
