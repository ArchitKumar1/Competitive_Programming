#include<bits/stdc++.h>
using namespace std;
#define ll long long int
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
	vector<ll>primes;
	vector<ll>answer;
	for(int i=2;i<650000;i++){
		if(isprime(i)) primes.push_back(i);
	}
	TC{

		int n;
		cin>>n;
		ll m=0;
		for(int i=0;i<n-1;i++) {
			answer.push_back(primes[i]*primes[i+1]);
			m=max(m,primes[i]*primes[i+1]);
		}
		answer.push_back(primes[n-1]*primes[0]);
		cout<<m<<endl;

		if(m>1000000000){
			cout<<"-1"<<endl;
		}
		else{
			for(int i=0;i<answer.size();i++) cout<<answer[i]<<" ";
			cout<<endl;
		}
		answer.clear();

	}

	return 0;
}
