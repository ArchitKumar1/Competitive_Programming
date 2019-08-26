#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;

int main()
{

	int n;
	cin>>n;
	ll num[n],m=0;
	for(int i=0;i<n;i++) cin>>num[i];
	sort(num,num+n);
	for(int i=0;i<n;i++) m=max(num[i]*(n-i),m);
	cout<<m<<endl;
	return 0;
}
