#include<bits/stdc++.h>

#define ll long long
#define TC int t;cin>>t;while(t--)
using namespace std;



class graph
{
	int v;
	list<int> *adj;
	public:
	graph(int n);
	void addedge(int u,int v);
	void bfs(int n);
};

graph::graph(int n)
{
	v=n;
	adj =new list<int>[v];
}
void graph::addedge(int u,int v)
{
	adj[u].push_back(v);
}

void graph::bfs(int s)
{
	bool *visited=  new bool[v];
	
	for(int i=0;i<v;i++)
	{
		visited[i]=false;
	}
	
	list<int> queue;
	
	visited[s]=true;
	
	queue.push_back(s);
	while(!queue.empty())
	{
		s=queue.front();
		cout<<s<<" ";
		queue.pop_front();
		
		for(list<int>::iterator it=adj[s].begin();it!=adj[s].end();it++ )
		{
			if(!visited[*it])
			{
				visited[*it]=true;
				queue.push_back(*it);
			}
		}
	}
}
int main()
{
    graph g(4);
    g.addedge(0,1);
    g.addedge(0,2);
    g.addedge(1,2);
    g.addedge(2,0);
    g.addedge(2,3);
    g.addedge(3,3);
    
    g.bfs(2);
    return 0;
    
}

