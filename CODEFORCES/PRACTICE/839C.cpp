#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;

const int maxn = 1e5 + 10;
vector<int> adj[maxn];

int vi[maxn]={0};

int leaf[maxn]={0};

void dfs(int s,int len,int par){
	vi[s] = 1;
	int l = 0;
	for(auto c : adj[s]){
		if(!vi[c]){
			if(c == par) continue;
			dfs(c,len+1,s);
			l++;
		}
	}
	if(l==0)
		leaf[s] = len;
}
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n;
	cin >> n;

	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		x--,y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0,0,-1);

	double ans = 0.0;
	double nleaf = 0.0;

	for(int i=0;i<n;i++){
		if(leaf[i] > 0){
			ans+= leaf[i];
			nleaf++;
		}
	}
	double a = ans/nleaf;
	cout.precision(10);
	cout << fixed;

	cout << a << endl;

	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif

	return 0;

}
