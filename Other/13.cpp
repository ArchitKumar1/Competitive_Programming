#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define pb push_back
using namespace std;


const int N = 10001;
vector<vector<int>> adj(N) ;
int vi[N]={0};
list<int> l;

void bfs(int s){
	l.push_back(s);
	vi[s] = 1;
	while(l.size()!=0){
		int x = l.front();
		l.pop_front();
		cout<< x << " ";
		for(auto i : adj[x]){
			if(vi[i] == 0){
				l.push_back(i);
				vi[i] = 1;
			}
		}
	}
}

void dfs(int s){
	vi[s] = 1;
	cout<< s<< " ";
	for(auto i : adj[s])
		if(!vi[i])
			dfs(i);
}
int main(){
	int n,no;
	cin >> n >> no;
	forn(i,no){
		int x,y;
		cin >> x >> y;
		adj[x].pb(y);
		adj[y].pb(x);
	}

	bfs(1);
	forn(i,N) vi[i] = 0;
	cout<<endl;
	dfs(1);
	cout <<
	return 0;

}
