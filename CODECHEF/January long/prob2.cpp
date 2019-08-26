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
	TC
	{
		int n,a,b;
		int bob=0,alice=0,both=0;
		cin >> n>> a>>b;
		ll arr[n];
		for(ll i=0;i<n;i++) cin>>arr[i];

		for(ll i=0;i<n;i++){
			if(arr[i]%a==0)
				bob++;
			if(arr[i]%b==0)
				alice++;
			if(arr[i]%a==0 && arr[i]%b==0)
				both++;
		}
		if(both>0)
		{
			if(bob>=alice)
				cout<<"BOB"<<endl;
			else
				cout<<"ALICE"<<endl;
		}
		else
		{
			if(bob>alice)
				cout<<"BOB"<<endl;
			else
				cout<<"ALICE"<<endl;
		}


	}
	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}

