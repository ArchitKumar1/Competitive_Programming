#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;


const int maxn = 100;
const int C = 100;
int a[maxn][maxn];
int dp[maxn][maxn][C];

int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n,cost;
	cin >> n >> cost;
	rep(i,1,n+1)
		rep(j,1,n+1)
			cin >> a[i][j];

	mset(dp,0);
	dp[1][1][a[1][1]] = 1;

	rep(i,1,n+1){
		rep(j,1,n+1){
			rep(k,0,cost+1){
				if(k - a[i][j]>=0){
					 dp[i][j][k] += dp[i - 1][j][k - a[i][j]];
					 dp[i][j][k] += dp[i][j - 1][k - a[i][j]];
				}
			}
		}
	}
	cout << dp[n][n][cost];

	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif


}
