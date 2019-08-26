#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
template<typename T>
bool isprime(T x){
	for(T i=2;i*i<=x;i++)
		if(x%i==0)
			return 0;
	return 1;
}

int main(){
	fastio
	TC{

	int n;
	ll answer;
	cin>>n;
	answer=n+n*(n+1)/2;
	cout<<answer<<"\n";
	}
	return 0;

}
