#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        int dp[n + 3][m + 3],a[n][m];
        for (int i = 0; i < n+3;i++){
            for (int j = 0; j < m + 3;j++){
                dp[i][j] = 0;
            }
        }
        for (int i = 0; i < n;i++){
            for (int j = 0; j < m;j++){
                cin >> a[i][j];
            }
        }
        for (int j = 1; j <= m;j++){
            for (int i = n; i >= 0;i--){
                dp[i][j] = max(dp[i + 1][j], a[i - 1][j - 1] + dp[i + 2][j]);
            }
        }
        int ans = 0;
        for (int j = 1; j <= m;j++){
            ans += dp[1][j];
        }
        cout << ans << endl;

        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= m;j++){
                cout << dp[i][j] << " ";
            }
            cout << endl;
        }
    }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}