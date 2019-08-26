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



	int n,k;
	cin>>n>>k;
	int arr[n];

	for(int i=0;i<n;i++)
		cin>>arr[i];
	int currcol;
	int precol=0;
	int mlength=1;
	int l=1;
	if(n==1)
	{
		cout<<"1";
		return 0;
	}
	for(int i=0;i<n-1;i++)
	{

		if(arr[i+1]!=arr[i])
		{
			l++;
			mlength=max(l,mlength);

		}
		else
		{
			l=1;
		}

	}
	cout<<mlength<<endl;


	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}

