#include<bits/stdc++.h>
using namespace std;
#define ll long long int

void solve(){
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int dp[n+2];
    dp[0] = 1;
    for (int i = 1; i < n;i++){
        if(a[i] > a[i-1]){
            dp[i + 1] = dp[i] + 1;
        }else{
            dp[i + 1] = 1;
        }
    }
    cout << dp[n] << endl;
}   
int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}