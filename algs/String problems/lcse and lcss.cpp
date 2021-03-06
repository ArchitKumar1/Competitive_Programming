#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;

int lcsst(string a,string b){
	
	int n = a.length();
	int m = b.length();
	int dp[n + 1][m + 1];
	mset(dp, 0);
	int ans = 0;
	for (int i = 1; i <=n;i++){
		for (int j = 1; j <=m;j++){
			if(a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
				ans = max(ans, dp[i][j]);
		}
	}
	return ans;
}
int lcsse(string a,string b){
	int n = a.length();
	int m = b.length();
	int dp[n + 1][m + 1];
	mset(dp, 0);

	for (int i = 1; i <= n;i++){
		for (int j = 1; j <= m;j++){
			if(a[i-1] == b[j-1])
				dp[i][j] = 1 + dp[i - 1][j - 1];
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][m];
}



int main()
{
	fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    string a, b;
    cin >> a >> b;
    cout << lcsse(a, b) << endl;
    cout << lcsst(a, b) << endl;
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
