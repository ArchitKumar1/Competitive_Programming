/*
Author : Archit Kumar
*/
#include<bits/stdc++.h>
using namespace std;
const long long INDEXM=1005;
#define ll long long
int main()
{
	
	ll n,sum;
	cin>>n>>sum;
	ll positions[n];
	ll indexes[INDEXM];
	ll mi=10000007;
	for(ll i=0 ;i<INDEXM ;i++ )
	{
		indexes[i]=10000007;
	}
	for(ll i=0 ;i<n ;i++ )
	{
		cin>>positions[i];
		indexes[positions[i]]=min(i,n-i);
	}
	
	for(ll i=0 ;i<n ;i++ )
	{
		ll x=positions[i];
		if(sum-x>=0 && indexes[sum-x]==10000007)
		{
			continue;
		}
		if(sum-x>=0 && (sum-x)!=x)
		{
			ll x=max(indexes[x],indexes[sum-x]);
			mi=min(mi,x);
		}
	}
	if(mi!=10000007)
		cout<<mi;
	else
		cout<<"-1";
	return 0;
}
