#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;

const int maxn = 1e5 + 10;
vector<int> adj[maxn];

int vi[maxn]={0};
int cats[maxn]={0};
int leaf[maxn]={0};
int k;

void dfs(int s, int cc){
	vi[s] = 1;
	if(cats[s] == 0)
		cc = 0;
	else
		cc += 1;
	if(cc > k)
		return;

	int l = 0;
	for(auto c : adj[s]){
		if(!vi[c]){
			dfs(c,cc);
			l++;
		}
	}
	if(l==0)
		leaf[s]=1;
}
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n;
	cin >> n >> k;

	for(int i=0;i<n;i++)
		cin >> cats[i];

	for(int i=0;i<n-1;i++){
		int x,y;
		cin >> x >> y;
		x--,y--;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	dfs(0,0);
	int ans = 0;

	for(int i=0;i<n;i++){
		if(leaf[i] == 1)
			ans++;
	}
	cout << ans <<endl;
	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif

	return 0;

}
