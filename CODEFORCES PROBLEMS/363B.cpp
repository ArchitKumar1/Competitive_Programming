#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n,k;
    cin >> n >> k;

    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int ans = INT_MAX, ind = -1, dp[n+1];
    dp[0] = 0;
    for (int i = 1; i <= n;i++){
        dp[i] = a[i-1] + dp[i - 1] ;
    }

    for (int i = k ; i <= n;i++){
        if(dp[i] - dp[i-k] < ans){
            ans = dp[i] - dp[i - k];
            ind = i - k;  
        }
        
    }
    cout << ind + 1 << endl;
}