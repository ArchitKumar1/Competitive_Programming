#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;
typedef vector<int,int>  vdi;
typedef vector<int> vi;
vector<Pair> v1;
bool isprime(int n){
	for(int i=2;i*i<=n;i++)if(n%i==0) return false;
	return true;
}
int main()
{
	fastio
	vector<int>primes;
	for(int i=2;i<650000;i++){
		if(isprime(i)) primes.push_back(i);
	}
	for(int i=0;i<100;i++) cout<<primes[i]<<" ";
	return 0;
}
