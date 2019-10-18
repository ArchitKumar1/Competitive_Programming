#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;

const int maxn = 1e5 + 10;
int c[maxn];
const long long INFLL = 0x3f3f3f3f3f3f3f3fLL;
long long dp[maxn][2];
string a[maxn],b[maxn];

int main()
{
	int n;
	cin >> n;
	for(int i=1;i<n+1;i++)
		cin >> c[i];

	for(int i=1;i<n+1;i++){
		string x;
		cin >> x;
		a[i] = x;
		reverse(x.begin(),x.end());
		b[i] = x;
	}
	dp[1][0] = 0;
	dp[1][1] = c[1];

	for(int i=2;i<=n;i++){
		dp[i][0] = INFLL;
		if(a[i-1] <= a[i])
			dp[i][0] = min(dp[i][0],dp[i-1][0]);
		if(b[i-1] <= a[i])
			dp[i][0] = min(dp[i][0],dp[i-1][1]);
		dp[i][1] = INFLL;
		if(a[i-1] <= b[i])
			dp[i][1] = min(dp[i][1],dp[i-1][0] + c[i]);
		if(b[i-1] <= b[i])
			dp[i][1] = min(dp[i][1],dp[i-1][1] + c[i]);
	}
	long long ans = min(dp[n][0],dp[n][1]);
	if(ans == INFLL) ans = -1;
	cout << ans <<endl;


	return 0;

}
