#include<bits/stdc++.h>
using namespace std;
const int maxn = 120;
int a[maxn][maxn], dp[maxn][maxn][maxn];
int main()
{
	int n,cost;
	cin >> n >> cost;
	for(int i=1;i<n+1;i++) for(int j=1;j<n+1;j++) cin >> a[i][j];
	memset(dp,0,sizeof(dp));dp[1][1][a[1][1]] = 1;
	for(int i=1;i<n+1;i++) for(int j=1;j<n+1;j++) for(int k=1;k<n+1;k++) if(k - a[i][j] >=0) dp[i][j][k] += dp[i-1][j][k - a[i][j]],dp[i][j][k] += dp[i][j-1][k - a[i][j]];
	cout << dp[n][n][cost];
}
