#include<bits/stdc++.h>
using namespace std;

const int inf = 1 << 30;
const int N = 101;
int adj[N][N];


int main()
{
	int n,m;
	cin >> n >> m;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {

			adj[i][j] = inf;
		}
	}

	for(int j = 0; j < m; ++j) {
		int x ,y;
		cin >> x >> y;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}



	int q;
	cin >> q;
	for(int j = 0; j < q; ++j) {
		int x ,y;
		cin >> x >> y;
		if(adj[x][y] == 1 || adj[y][x] == 1)
			cout << "YES" <<endl;
		else
			cout << "NO" <<endl;
	}
	return 0;
}

