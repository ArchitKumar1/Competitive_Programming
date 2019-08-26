#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;


int main()
{
    //fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int m = 9;
    int a[m] = {1, 1,1,1,1,3, 5, 7, 9};

    int dp[n + 1];
    mset(dp, 0);
    dp[0] = 1;
    for (int i = 0; i <m;i++){
        for (int j = a[i]; j <=n;j++){
            dp[j] += dp[j - a[i]];
        }
    }
    cout << dp[n];
    for (int i = 0; i <= n;i++){
        cout << dp[i] << " ";
    }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
