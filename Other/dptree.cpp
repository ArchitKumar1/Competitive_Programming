#include<bits/stdc++.h>
using namespace std;

const int N = 1001;

vector<int> adj[N];
vector<int> vi(N);
void dfs(int v){
	vi[v] = 1;
	cout << v <<" ";
	for(auto c:adj[v])
		if(!vi[c])
		dfs(c);
}
int main()
{
	int n;
	cin >> n;

	for(int i=1;i<n;i++){
		int x,y;
		cin >> x >> y;
		adj[x].push_back(y);
		adj[y].push_back(x);

	}
	dfs(1);
	return 0;
}

