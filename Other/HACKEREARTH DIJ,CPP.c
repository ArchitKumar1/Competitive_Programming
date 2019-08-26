#include<bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;
const int N = 101;
int adj[N][N];

int n,m;
vector<int> dijk(int A){
	vector<int> dist(N);
	vector<int> vis(N);

	for(int i=1;i<n+1;i++)
		dist[i] = inf;

	dist[A]=0;

	for(int i=1;i<n+1;i++){
		int cur=-1;
		for(int j=1;j<n+1;j++){
			if(!vis[j] && cur ==-1 && dist[j]<dist[cur])
				cur=j;
		}
		vis[cur]=true;
		for(int j=1;j<n+1;j++){
			if(dist[cur]+ adj[cur][j] < dist[j])
				dist[j]= dist[cur]+ adj[cur][j];
		}
	}

	//return dist;
	return dist;
}
int main()
{
	cin >> n >> m;
	for(int i = 1; i < n+1; ++i) {
		for(int j = 1; j < n+1; ++j) {
		  adj[i][j] = inf;
		}
	}
	for(int i=0;i<m;i++){
		int x,y,z;
		cin >> x >> y >> z;
		adj[x][y] = z;

	}
	vector<int> dist = dijk(1);

	for(int i=2;i<n+1;i++)
		cout << dist[i] <<" ";

	return 0;
}

