#include<bits/stdc++.h>

#define ll long long
#define TC int t;cin>>t;while(t--)
using namespace std;
const int N=10005;
vector<int> adj[10005];
bool visited[10005]={false};
int distance[10005]={0};

void dfs(int s,int count,int distance[])
{
	
	visited[s]=true;
	distance[s]=count;
	
	cout<<s<<" ";
	count+=1;
	for(int i=0;i<adj[s].size();i++)
	{
		if(visited[adj[s][i]]==false)
		{
			dfs(adj[s][i],count,distance);
		}
		count-=1;
	}
}
int main()
{
	int nodes,edges,u,v;
	cin>>nodes>>edges;
	int distance[10005]={0};
	for(int i=0;i<edges;i++)
	{
		cin>>u>>v;
		adj[u].push_back(v);
	}
	int count=0;
	dfs(0,count,distance);
	cout<<endl;
	for(int i=0;i<nodes;i++)
		cout<<distance[i]<<" ";
	return 0;
	
}
