#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;

int main()
{
	TC
	{
		ll k,d0,d1;
		cin>>k>>d0>>d1;
		ll remainder;
		ll power=k-2;
		if(power%2!=0)
			remainder=1;
		else
			remainder =0;
		ll x=(2*d0+2*d1)%3;
		ll total=(x+(remainder*(d0+d1))%3)%3;
		if(total==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}

