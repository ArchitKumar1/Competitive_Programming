#include<bits/stdc++.h>

#define ll long long
#define TC int t;cin>>t;while(t--)
using namespace std;

int main()
{
	int v,no;
	cin>>v;
	no=v-1;

    vector<int> adj[v+1];
    int level[v+1]={0};
    bool visited[v+1]={0};


    int u,w;
    for(int i=0;i<no;i++)
    {
    	cin>>u>>w;
    	adj[u].push_back(w);
    	adj[w].push_back(u);

	}

	list<int> q;
	int s;
	int c;

	s=1;

	visited[s]=true;
	q.push_back(s);

	while(!q.empty())
	{
		c=q.front();
		q.pop_front();
		//cout<<c<<" ";
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
	int x;
	cin>>x;
	int l=0;
	for(int i=1;i<v+1;i++){
		cout<<level[i]<<" ";
	}
	cout<<endl;
	for(int i=1;i<v+1;i++){
		if(level[i]==x){
			cout<<i<<" ";
		}
	}
	cout<<l;


	return 0;

}
