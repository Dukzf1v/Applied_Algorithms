#include <bits/stdc++.h>
using namespace std;

const int MAX = 20;
int n, K, Q;
int d[MAX], c[MAX][MAX], minCost = 1e9;
int x[MAX], y[MAX], visited[MAX];
int segment = 0, nbr, f, fOpt=1e9, load[MAX];

void input(){
	cin >> n >> K >> Q;
	for(int i = 1; i <= n; i++){
		cin >> d[i];
	}
	for(int i = 0; i <= n; i++){
		for(int j = 0; j <= n; j++){
			cin >> c[i][j];
			if(i!=j) minCost = min(minCost,c[i][j]);
		}
	}
}

int updateBest(){
	if(f<fOpt) fOpt = f;
	return fOpt;
}

int checkY(int v, int k){
	if(v==0) return 1;
	if(d[v] > Q) return	0;
	if(visited[v]) return 0;
	return 1;
}

int checkX(int v, int k){
	if(v>0&&visited[v]) return 0;
	if(load[k] + d[v] > Q) return 0;
	return 1;
}

void TryX(int s, int k){
	if(s==0){
		if(k < K) TryX(y[k+1],k+1);
		return;
	}
	for(int v = 0; v <= n; v++){
		if(checkX(v,k)){
			x[s] = v;
			visited[v] = 1;
			load[k] += d[v];
			segment++;
			f = f + c[s][v];
			if(v>0){
				if(f + (n+nbr-segment)*minCost < fOpt){
					TryX(v,k);
				}
			} else {
				if(k==K){
					if(segment == n+nbr) updateBest();
				} else {
					if(f + (n+nbr-segment)*minCost < fOpt){
						TryX(y[k+1],k+1);
					}
				}
			}
			f -= c[s][v];
			load[k] -= d[v];
			segment--;
			visited[v] = 0;
		}
	}
}

void TryY(int k){
	int s = 0;
	if(y[k-1] > 0) s = y[k-1] + 1;
	for(int v = s; v <= n; v++){
		if(checkY(v,k)){
			y[k] = v;
			if(v>0) segment++;
			f += c[0][v];
			visited[v] = 1;
			load[k] += d[v];
			if(k<K){
				TryY(k+1);
			} else {
				nbr = segment;
				TryX(y[1],1);
			}
			segment--;
			f -= c[0][v];
			load[k] -= d[v];
			visited[v] = 0;
		}

	}
}

int main(){
	input();
	y[0]=0;d[0]=0;
	TryY(1);
	cout << fOpt;
	return 0;
}