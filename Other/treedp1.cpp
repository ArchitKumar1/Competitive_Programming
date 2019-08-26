#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define Forn(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
using namespace std;


const int N = 10001;
int a[N],vi[N]={0};
vector<int> adj[N];
int msum = 0;

void dfs(int s,int sum){
	vi[s] = 1;
	sum = sum+a[s];
	for(auto i : adj[s]) if(!vi[i]) dfs(i,sum);
	msum = max(msum,sum);
}
int main(){
	int n;
	cin >> n;

	forn(i,n-1){
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}
	Forn(i,1,n+1) cin >> a[i];
	dfs(1,0);
	cout << msum <<endl;
	return 0;

}
