#include<bits/stdc++.h>
#define ll long long int
using namespace std;
bool isprime(ll n)
{
	if(n==1 || n==0)
		return 0;
	for(ll i=2;i<=sqrt(n);i++)
	{
		if(n%i==0)
			return 0;
	}
	return 1;
}
int totaldivisors(ll n)
{
	ll c=0;
	
	if(n==1)
		return 1;
	double sq=sqrt(n);
	if(sq-int(sq)>0)
	{
		for(ll i=1;i<sqrt(n);i++)
		{
			if(n%i==0)
				c++;
		}
	return 2*c;
	}
	else{
	
	for(ll i=1;i<sqrt(n);i++)
	{
		if(n%i==0)
			c++;
	}
	return 2*c+1;
	}
}
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
	
	ll l,r;
	cin >> l>> r;
	ll count=0;
	for(ll i=l;i<=r;i++)
	{
		if(isprime(totaldivisors(i)))
			count++;
	}
	cout<<count;
//	cout<<totaldivisors(9);
	}
	
	return 0;
}
