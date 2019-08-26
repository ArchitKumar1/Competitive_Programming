#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;
typedef vector<int,int> vdi;
typedef vector<int> vi;
vector<Pair> v1;


int main()
{
	int n,q;
	cin>>n>>q;
	ll a[n+1], b[n+1],temp;
	a[0]=0,b[0]=0;
	for(int i=1;i<n+1;i++) {
		cin>>temp;
		a[i]=temp+a[i-1];
	}
	for(int i=0;i<n;i++) {
		cin>>temp;
		b[i]=temp+b[i-1];
	}
	for(int i=0;i<q;i++){
		int x,l,r;
		cin>>x>>l>>r;
		if(x==1) cout<<a[r]-a[l-1]<<endl;
		else cout<<b[r]-b[l-1]<<endl;
	}
	return 0;
}
