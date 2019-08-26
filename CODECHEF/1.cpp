#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define TC int t; cin>>t; while(t--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

const int N=100000;
bool primes[N+1];


void seive(){
	for(int i=2;i*i<=N;i++){
		if(primes[i]==1){
			for(int j=i*i;j<=N;j=j+i)
				primes[j]=0;
		}
	}
}
int main()
{
	fastio
	memset(primes, true, sizeof(primes));

	seive();
	vector<int> v;

	for(int i=2;i<=N;i++){
		if(primes[i]==1)
			v.push_back(i);
	}

	TC{

		int n;
		cin>>n;

		for(int i=0;i<n-1;i++){
			ll x=(ll)v[i]*(ll)v[i+1];
			cout<<x<<" " ;
		}
		ll x=(ll)v[n-1]*(ll)v[0];
		cout<<x;
		cout<<endl;

	}

	return 0;
}
