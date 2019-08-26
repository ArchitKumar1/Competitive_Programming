#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define Forn(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
using namespace std;


const int N = 10001;
char a[N];int vi[N]={0};
int subtree[N][26];

vector<int> adj[N];


void dfs(int s){
	vi[s] = 1;
	for(auto c : adj[s])
		if(!vi[c]) {
			dfs(c);
			forn(i,26)
				subtree[s][i]+=subtree[c][i];
		}
	subtree[s][a[s]-'a']++;
}
int main(){
	memset(subtree,0,sizeof(subtree));
	int n,q;
	cin >> n >> q;

	Forn(i,1,n+1)
		cin >> a[i];

	forn(i,n-1){
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	dfs(1);

	forn(i,q) {
		int x;string y;
		cin >> x >> y;
		int f[26]={0};
		int ans=0;

		forn(i,y.size())
			f[y[i]-'a']++;
		forn(i,26)
			ans+=max(0,f[i]-subtree[x][i]);

		cout << ans <<endl;
	}
	return 0;

}
