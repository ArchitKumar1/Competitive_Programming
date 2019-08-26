#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;

const int maxn = 110000;


int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int cost = 15;
	int S[4]= {1,2,3,4};
	int dp[100000];
	mset(dp,0);
	dp[0] = 1;
	for(int i=0;i<4;i++){
		for(int j=S[i];j<=20000;j++){
				dp[j] += dp[j-S[i]];
		}
	}

	cout << dp[1000] << endl;

	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif

	return 0;

}
