#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;
typedef vector<int,int>  vdi;
typedef vector<int> vi;
vector<Pair> v1;

int main()
{
	TC{

		ll n,p;
		cin>>n>>p;
		ll mv=0;
		ll r;
		if(n%2==0) r=n/2;
		else r=n/2+1;
		mv=(p-r+1)*(p-r+1)+(p-n)*(2*p-r-n+1);
		if(n==2 || n==1)
			mv=p*p*p;
		cout<<mv<<endl;

	}
	return 0;
}
