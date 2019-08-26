#include<bits/stdc++.h>
using namespace std;

const int N = 200000;
vector<vector<int>> adj(N);
int vi[N]= {0};

void dfs(int s){
	vi[s] = 0;
	for(auto c: adj[s]){
		if(vi[c]) dfs(c);
	}
}
int main(){
	int n,m;
	cin >> n >> m;
	for(int i=0;i<m;i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);
		vi[x] = 1;
		vi[y] = 1;
	}

	for(int i=1;i<=n;i++)
		if(vi[i] == 1){
			cout << "NO" <<endl;
			return 0;
	}
	cout << "YES";

	return 0;
}
