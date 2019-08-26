#include<bits/stdc++.h>
#define ll long long
#define TC int t; cin>>t; while(t--)
using namespace std;
template<typename T>
T A(T a,T b, T m){
	T res=1;
	a=a%m;
	while(b>0){
		if(b&1)
			res=res * a % m;
		a=a * a % m;
		b=b/2;
	}
	return res;
}
int main()
{
	TC{
	ll n,k,p;
	cin>>n>>k>>p;
	int sum=0;
	for(ll i=1;i<=n;i++)
		sum=(sum+A(i,k,p))%p;
	cout<<sum<<endl;

	}
	return 0;
}

