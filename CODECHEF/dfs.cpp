#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define TC int t; cin>>t; while(t--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);


const int n=10;
vector<int> v[n];
bool visited[n]={0};


void dfs(int s){
	cout<<s<<" ";
	visited[s]=1;
	for(int i=0;i<v[s].size();i++){
		if(visited[v[s][i]]==0)
			dfs(v[s][i]);
	}
}

int main()
{

	int no;
	cin>>no;
	for(int i=0;i<no;i++){
		int x,y;
		cin>>x>>y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	dfs(1);

	return 0;
}

