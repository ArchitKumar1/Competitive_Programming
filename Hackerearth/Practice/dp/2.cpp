#include<bits/stdc++.h>

using namespace std;

const long long int N = 550000;
vector<long long int> primes;
vector<long long int> ok(N, 1);
long long int dp[N],dp2[N];
void seive(){
    for (long long int i = 2; i * i <= N;i++){
        if(ok[i]){
            for (long long int j = i * i; j <= N;j = j+i){
                ok[j] = 0;
            }
        }
    }
    for (long long int i = 2; i < N;i++){
        if(ok[i]){
            primes.push_back(i);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    seive();
    primes.resize(700);
    long long int n;
    cin >> n;
    long long int a[n];
    for (long long int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (long long int i = 1; i <= n;i++){
        dp[i] = dp[i - 1] + a[i-1];
    }
    dp2[0] = 0;
    dp2[1] = 0;
    long long int ans = 0;
    for (int i = 2; i <= n;i++){
        dp2[i] = dp2[i - 1];
        for(long long int e : primes ){
            if(e<=n){
                if(e == i){
                    dp2[i] = max(dp2[i],dp[i]);
                }else{
                    dp2[i] = max(dp2[i], dp2[i-e-1] + dp[i] - dp[i-e]);
                }
            }
        }
    }
        
    cout << dp2[n] << endl;
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}