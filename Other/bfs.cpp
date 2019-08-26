#include<bits/stdc++.h>

#define ll long long
#define TC int t;cin>>t;while(t--)
using namespace std;


int main()
{
	TC{
	const int MAX=100010;
	vector<int> adj[MAX];
	int level[MAX]={0};
	bool visited[MAX]={0};
	int v,no;
	cin>>v;
	cin>>no;

    int u,w;
    for(int i=0;i<no;i++){
    	cin>>u>>w;
    	adj[u].push_back(w);
    	adj[w].push_back(u);

	}
	list<int> q;
	int s=1;
	int c;
	visited[s]=true;
	q.push_back(s);

	while(!q.empty())
	{
		c=q.front();
		q.pop_front();
		for(int it=0;it<adj[c].size();it++)
		{
			if(visited[adj[c][it]]==false)
			{
				level[adj[c][it]]=level[c]+1;
				visited[adj[c][it]]=true;
				q.push_back(adj[c][it]);
			}
		}
	}

	cout<<level[v]<<endl;
	}
	return 0;

}
