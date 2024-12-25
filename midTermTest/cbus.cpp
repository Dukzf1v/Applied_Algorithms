#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n, k, D;                    
int c[2 * MAX + 1][2 * MAX + 1]; 
int x[2 * MAX + 1];          
bool visited[2 * MAX + 1];   
int totalDist[MAX + 1] = {0};     
int load = 0;                    
int curCost = 0, optimalCost = INT_MAX, minCost = INT_MAX;

void inp() {
    cin >> n >> k >> D;
    for (int i = 0; i <= 2 * n; i++) {
        for (int j = 0; j <= 2 * n; j++) {
            cin >> c[i][j];
            if (i != j) minCost = min(minCost, c[i][j]); 
        }
    }
}

bool check(int v) {
    if (visited[v]) return false;      
    if (v > n && !visited[v - n]) return false; 
    if (v <= n && load == k) return false; 
    return true;
}

bool validateDistances() {
    for (int i = 1; i <= n; i++) {
        if (totalDist[i] < D) return false;
    }
    return true;
}

void update() {
    if (validateDistances()) { 
        int finalCost = curCost + c[x[2 * n]][0]; 
        if (finalCost < optimalCost) {
            optimalCost = finalCost;
        }
    }
}

void Try(int k) {
    for (int v = 1; v <= 2 * n; v++) { 
        if (check(v)) {
            x[k] = v;
            visited[v] = true;
            curCost += c[x[k - 1]][v];
            load += (v <= n) ? 1 : -1;

            if (v <= n) totalDist[v] += c[x[k - 1]][v];
            else totalDist[v - n] += c[x[k - 1]][v];

            if (k == 2 * n) {
                update(); 
            } else if (curCost + (2 * n - k + 1) * minCost < optimalCost) {
                Try(k + 1);
            }

            visited[v] = false;
            curCost -= c[x[k - 1]][v];
            load -= (v <= n) ? 1 : -1;

            if (v <= n) totalDist[v] -= c[x[k - 1]][v];
            else totalDist[v - n] -= c[x[k - 1]][v];
        }
    }
}

int main() {
    inp();
    x[0] = 0;
    visited[0] = true;
    Try(1);
    cout << (optimalCost == INT_MAX ? -1 : optimalCost) << endl;
    return 0;
}
