#include<bits/stdc++.h>
using namespace std;
vector<int> adj[1001];
vector<bool> visited(1001,false);
int n, m, cnt = 0;

void inp(){
	cin >> n >> m;
	for(int i = 0; i < m; i++){
		int x,y; cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
}

void dfs(int u){
	cout << u << " ";
	visited[u] = true;
	for(auto v : adj[u]){
		if(!visited[v]){
			dfs(v);
		}
	}
}

void findComponents(){
	for(int i = 1; i <= n; i++){
		if(!visited[i]){
			cnt++;
			cout << endl;
			dfs(i);
		}
	}
}

int main(){
	inp();
	findComponents();
	cout << endl << cnt;
	return 0;
}