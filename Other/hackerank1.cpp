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
	int s,a;
	cin>>s;
	ll scores[s];
	for(int i=0;i<s;i++) cin>>scores[i];
	cin>>a;
	ll alice[a];
	for(int i=0;i<a;i++) cin>>alice[i];
	ll ranks[a];

	int position;

	for(int i=0;i<a;i++){
		while(scores[pos]<)
	}
	return 0;
}
