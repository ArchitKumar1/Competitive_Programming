#include<bits/stdc++.h>
using namespace std;


int main() {

#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    string a, b;
    cin >> a >> b;

    int n = a.length();
    int m = b.length();

    vector<vector<int>> dp1(n+1, vector<int>(m+1, 0));
    vector<vector<int>> dp2(n+1, vector<int>(m+1, 0));
    vector<vector<int>> dp3(n+1, vector<int>(m+1, 0));
    
    int ans = 0;
    for (int i = 1; i <= n;i++) {
        for (int j = 1; j <= m;j++) {
            dp1[i][j] = (a[i - 1] == b[j - 1]) ? 1 + dp1[i - 1][j - 1] : max(dp1[i - 1][j], dp1[i][j - 1]);
            dp2[i][j] = (a[i - 1] == b[j - 1]) ? 1 + dp2[i - 1][j - 1] : 0;
            ans = max(ans, dp2[i][j]);
        }
    }
    cout << dp1[n][m] << " ";;
    cout << ans << " ";
    return 0;
}