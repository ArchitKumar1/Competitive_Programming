#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n;
    cin >> n;
    int grid[n+1][n+1];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            char x;
            cin >> x;
            grid[i + 1][j + 1] = x-'0';
        }
    }
    int dp[n+1][n+1];
    int dp2[n+1][n+1];
    memset(dp,0,sizeof(dp));
    memset(dp2,0,sizeof(dp2));
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp[i][j] = grid[i][j] +  dp[i-1][j] + dp[i][j-1] -dp[i-1][j-1];
        }
    }
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=n;j++){
    //         cout << dp[i][j] << " ";
    //     }cout << endl;
    // }
    int ans = INT_MAX;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            dp2[i][j] = dp2[i][j-1] + grid[i][j];
        }
    }
    
    for(int  i=1;i<=n;i++){
        int temp = 0;
        int rev = dp2[i][n] - 2*dp2[i][n/2];
        int psum = dp2[i][n] -2*dp2[i][n/2];
       // cout << "I " << i << "rev" <<rev << endl;
        int a,b,c,d;
        a = dp[n][n] - 2*dp[n][n/2];
        a = a - psum;
        ans = min(ans,abs(a - rev));
        ans = min(ans,abs(a + rev)); 
    }
    cout << ans << endl;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;

}