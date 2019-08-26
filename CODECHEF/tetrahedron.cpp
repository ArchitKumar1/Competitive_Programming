#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);


const int N=1e7;
const ll mod=1e9 +7;
int dp[2][N];

int main()
{

	int n=9999999;
	dp[0][1]=0;
	dp[1][1]=1;

	for(int i=2;i<=n;i++){
		dp[0][i]=(3LL*dp[1][i-1])%mod;
		dp[1][i]=(1LL*dp[0][i-1]+2LL*dp[1][i-1])%mod;
	}
	cout<<dp[0][n];
	return 0;
}
