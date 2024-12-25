#include <iostream>
#include <queue>
#include <utility>
using namespace std;

typedef pair<int,int> ii;
int a[1005][1005];
int d[1005][1005];
int m, n, r, c;
int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
queue<ii> qe;

int solve() {
    qe.push(ii(r, c));
    a[r][c] = 1; 
    d[r][c] = 0; 

    while (!qe.empty()) {
        ii u = qe.front();
        qe.pop();
        for (int i = 0; i < 4; i++) {
            int x = u.first + dx[i];
            int y = u.second + dy[i];

            if (x < 0 || x >= m || y < 0 || y >= n) {
                return d[u.first][u.second] + 1;
            }

            if (a[x][y] == 0) {
                d[x][y] = d[u.first][u.second] + 1; 
                qe.push(ii(x, y));
                a[x][y] = 1; 
            }
        }
    }
    return -1; 
}

int main() {
    cin >> m >> n >> r >> c;
    r--; c--; 
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> a[i][j];
        }
    }
    int result = solve();
    cout << result;
}
