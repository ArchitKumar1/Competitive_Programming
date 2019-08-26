#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main()
{
	ll n = 500;
	ll arr[] = {1,2,3,4};
	ll m = sizeof(arr)/sizeof(arr[0]);
	ll dp[n+1];
	memset(dp, 0, sizeof(dp));
	dp[0] = 1;

	for(ll i=0; i<m; i++)
		for(ll j=arr[i]; j<=n; j++)
			dp[j] += dp[j-arr[i]];

    cout << dp[n];
 	return 0;
}
