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
	IOS
	TC
	{
		ll n,w;
		cin>>n>>w;
		int digits;
		if(abs(w)>9 or w==9)
			cout<<"0";
		if(n==2)
			if(w>=0)
				cout<<9-w<<endl;
			else
				cout<<10+w<<endl;
		else
		{
			if(w>=0)
			{
				ll ans=1;
				for(int i=0;i<n-2;i++)
				{
					ans=ans*10;
					ans=ans%mod;
				}
				ans=ans*(9-w)%mod;
				cout<<ans<<endl;
			}
			else
			{
				ll ans=1;
				for(int i=0;i<n-2;i++)
				{
					ans=ans*10;
					ans=ans%mod;
				}
				ans=ans*(10+w)%mod;
				cout<<ans<<endl;
			}
		}
	}






	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}
