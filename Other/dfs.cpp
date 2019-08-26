#include<bits/stdc++.h>

#define ll long long
#define TC int t;cin>>t;while(t--)
using namespace std;


const int MAX=1010;
vector<int> adj[MAX];
bool visited[MAX]={false};
int distance[MAX]={INT_MAX};

void dfs(int s)
{
	visited[s]=true;
	cout<<s<<" ";
	for(int i=0;i<adj[s].size();i++){
		if(visited[adj[s][i]]==false){
			dfs(adj[s][i]);
		}
	}
}
int main()
{
	int nodes,edges,u,v;
	cin>>nodes>>edges;

	for(int i=0;i<edges;i++){
		cin>>u>>v;
		adj[u].push_back(v);
	}

	for(int i=0;i<nodes;i++){
		if(visited[i]==false){
			dfs(i);
		}
	}


	return 0;

}
