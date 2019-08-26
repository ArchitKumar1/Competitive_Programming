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
		int n;
		cin>>n;
		int count=0;
		for(int i=13;i>=0;i--)
		{
			if(n&(1<<i)) count++;
		}
		cout<<count<<endl;
	}

	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}

