#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);

ll mod =1e+9 +7;
typedef pair<int,int> Pair;

int arr[101][101];
int main()
{
	IOS
	TC
	{
		int sum=0;
		int x;
		for(int i=0;i<100;i++)
		{
			cin >> x;
			if(x<=30)
				sum++;

		}
		if(sum>=60)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}



	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}
