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
	fastio
	ll m,n,a,b,indma,indmi;
	cin>>n>>m;
	ll arr1[n],arr2[m];
	for(int i=0;i<n;i++) cin>>arr1[i];
	for(int i=0;i<m;i++) cin>>arr2[i];
	ll mi=*min_element(arr2,arr2+m);
	ll ma=*max_element(arr1,arr1+n);
	for(int i=0;i<m;i++) if(arr2[i]==mi) indmi=i;
	for(int i=0;i<n;i++) if(arr1[i]==ma) indma=i;
	for(int i=0;i<n;i++) cout<<i<<" "<<indmi<<endl;
	for(int i=0;i<m;i++) if(i!=indmi) cout<<indma<<" "<<i<<endl;
	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}



