#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;
const int MAX=100010;
ll height[MAX];
int rect[100000][500]={0};
vector<Pair> v1;
int main()
{

	int n;
	cin>>n;
	int x,y;
	for(int i=0;i<n;i++){
		cin>>x>>y;
		rect[x][y]=1;
		v1.push_back(make_pair(x,y));
	}

	return 0;
}
