#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin>> n;
	ll mi=10000000005;
	while(n!=mi)
	{
		mi=n;
		for(ll i=n-1;i>=2;i--)
		{
			if(n%i!=0)
				n=n-i;
				break;
		}
	}
	cout<<mi;
	return 0;
}
