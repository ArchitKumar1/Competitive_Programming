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
    memset(dp,0,sizeof(dp));
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
    ans = min(ans,dp[n][n] - 2 * dp[n][n/2]) ;
    
    for(int  i=1;i<=n;i++){
        int temp = 0;

        for(int j=1;2*j<n;j++){
            temp+=grid[i][j];
            //if(i == 3) cout << "G" << grid[i][j] << " ";
        }
        //cout << i << " " << temp << endl;
        for(int j = (n+1)/2;j<=n;j++){
            temp -= grid[i][j];
            //if(i == 3) cout << "G" << grid[i][j] << " ";
        }
        //cout << i << " " << temp << endl;
        int x = 0;
         
        x = dp[n][n] - 2 * dp[n][n/2] ;
        //cout << "x " << x<< endl;
        x -= (dp[i][n] - 2 *dp[i][n/2]) - (dp[i-1][n] - 2 * dp[i-1][n/2]) ;
        //cout << "x " << x<< endl;
        x += temp;
        //cout << "x " << x<< endl;
        
        ans = min(ans , abs(x));
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