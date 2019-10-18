#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;


const int maxn = 1e5 +100;

int dp[maxn];

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	string s;
	cin >> s;
	int n = s.length();
	mset(dp,0);

	forn(i,n){
		if(s[i] == s[i+1])
			dp[i+1] = 1;
	}
	for(int i=2;i<=n;i++){
		dp[i] += dp[i-1];
	}
	int q;
	cin >> q;
	forn(i,q){
		int x,y;
		cin >> x >> y;
		cout << dp[--y] - dp[--x] << endl;
	}
	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif

	return 0;

}
