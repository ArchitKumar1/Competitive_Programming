#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;

ll dp[1001][1001];
int main()
{
	int m,n;
	cin>>n>>m;
	ll arrofn[n],arrofm[m];
	for(int i=0;i<n;i++) cin>>arrofn[i];
	for(int i=0;i<m;i++) cin>>arrofm[i];

	set<Pair> s1;
	cout<<s1.size();
	while(s1.size()!=n+m-1)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				s1.insert(make_pair(i,j));
			}
		}
	}
	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}

