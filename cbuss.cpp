#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_CUSTOMERS = 50;
const int INF = 1e9;
int n, K, minCost = INF;
int C[2*MAX_CUSTOMERS+1][2*MAX_CUSTOMERS+1];
int x[2*MAX_CUSTOMERS+1], xOpt[2*MAX_CUSTOMERS+1];
int currentCost = 0, load = 0, optimalCost = INF;
bool visited[2*MAX_CUSTOMERS+1];

bool isValid(int v, int k){
    if(visited[v]) return false;
    if(v>n){
        if(!visited[v-n]) return false;
    } else {
        if(load==K) return false;
    }
    return true;
}

void updateSolution(){
    if(currentCost+C[x[2*n]][0] < optimalCost){
        optimalCost = currentCost + C[x[2*n]][0];
        for(int i = 0; i < 2*n; i++){
            xOpt[i] = x[i];
        }
    }
}

void Try(int k){
    for(int v = 1; v <= 2*n; v++){
        if(isValid(v,k)){
            x[k] = v;
            visited[v] = true;
            currentCost += C[x[k-1]][v];
            load += (v>n?-1:1);
            if(k==2*n){
                updateSolution();
            } else {
                if(currentCost + (2*n+1-k)*minCost < optimalCost){
                    Try(k+1);
                }
            }
            visited[v] = false;
            currentCost -= C[x[k-1]][v];
            load -= (v>n?-1:1);
        }
    }
}

void input(){
    for(int i = 0; i <= 2*n; i++){
        for(int j = 0; j <= 2*n; j++){
            cin >> C[i][j];
            if(i!=j){
                minCost = min(minCost, C[i][j]);
            }
        }
    }
}

int main(){
    cin >> n >> K;
    input();
    x[0] = 0;
    visited[0] = true;
    Try(1);
    cout << optimalCost;
    return 0;
}