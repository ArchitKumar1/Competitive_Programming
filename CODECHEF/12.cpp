#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 123456;

vector<int> primes;
vector<int> ok(N + 10, 1);
vector<int> ans(N + 10, 0);
int dp[N + 10][5];
void seive(){
    for (int i = 2; i*i <= N;i++){
        if(ok[i]){
            primes.push_back(i);
            for (int j = i; j <=N;j = j+i){
                ok[j] = 0;
                ans[j] += 1;
            }
        }
    }
}
int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    seive();
    for (int i = 1; i <=N;i++){
        for (int j = 1; j <6;j++){
            if(ans[i] == j){
                dp[i][j-1] = dp[i - 1][j-1] + 1;
            }else{
                dp[i][j-1] = dp[i - 1][j-1];
            }
        }
    }

    int t;
    cin >> t;
    while(t--){
        int a, b, k;
        cin >> a >> b >> k;
        cout << dp[b][k-1] - dp[a -1][k-1] << endl;
    }
    // for (int i = 0; i < 1000;i++){
    //     cout << i << " " << ans[i] << endl;
    // }

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}