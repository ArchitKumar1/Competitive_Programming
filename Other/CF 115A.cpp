#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define Forn(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
using namespace std;


const int N = 100;
int a[N],vi[N]={0};
vector<int> adj[N];

int d[N]= {0};


void dfs(int s){
	vi[s] = 1;

	for(auto i : adj[s])
		if(!vi[i]){
			dfs(i);
		}

}
int main(){
	int n;
	cin >> n;
	for(int i = 2; i <=n;i++){
		int x,y,z;

	}

	dfs(0);
	cout << msum <<endl;
	return 0;

}
