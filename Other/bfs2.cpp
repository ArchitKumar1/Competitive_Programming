#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;


vector<int> v[20];
int level[20]={0};
bool vis[20];
void bfs(int s)
{
	list<int>q;
	q.push_back(s);
	level[s]=0;
	vis[s]=true;
	while(!q.empty())
	{
		int p=q.front();
		q.pop_front();
		cout<<p<<endl;
		for(int i=0;i<v[p].size();i++)
		{
			if(vis[v[p][i]]==false)
			{
				level[v[p][i]]=level[p]+1;
				q.push_back(v[p][i]);
				vis[v[p][i]]=true;
			}
		}
	}
}

int main()
{
	IOS
	int n,x,y,s;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		cin>>x>>y;
		v[x].push_back(y);
	}


	cin>>s;

	bfs(3);
	for(int i=0;i<20;i++)
	{
		cout<<level[i]<<" ";
	}
	cout<<endl;
	for(int i=0;i<20;i++)
	{
		cout<<vis[i]<<" ";
	}



//	cout<<level[s];


	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}

