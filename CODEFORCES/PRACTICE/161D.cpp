#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
using namespace std;

const int N = 10001;

int vi[N]={0};

int chil[N]={0};
vector<int> adj[N];

void dfs(int s){


}

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n;
	cin >> n;

	forn(i,n-1){
		int x;
		cin >> x >> y;
		adj[y].pb(x);
		adj[x].pb(x);
	}
	dfs(1);

	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif

	return 0;

}
