#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
using namespace std;


const int N = 10001;
vector<vector<int>> adj(N) ;
int vi[N]={0};

void dfs(int s){
	vi[s] = 1;
	cout<< s<< " ";
	for(auto i : adj[s]){
		if(!vi[i])
			dfs(i);
	}
}
int main(){
	int n;
	cin >> n;
	int no;
	cin >> no;

	forn(i,no){
		int x,y;
		cin >> x >> y;
		//x--;y--;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	dfs(1);
	return 0;

}
