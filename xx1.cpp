#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 234567;
vector<int>  edge[N];
vector<ll> dp(N,0), val(N,0);
ll ans = (ll)-1e15;

void dfs(ll s ,ll par){
    ll sum = (ll)1e15;
    for(auto c : edge[s]){
        if(c == par) continue;
        dfs(c, s);
        sum = min(dp[c], sum);
    }
    ans = max(ans, val[s] - sum);
    dp[s] = min(sum,val[s]);
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ll n;
    cin >> n;
    // dp.resize(n);
    // val.resize(n);
    // edge.resize(n);
    for(ll i=0LL;i<n;i++){
        cin >> val[i];
    }
    
    for (ll i = 0LL; i < n;i++){
        ll x;
        cin >> x;
        if(x == -1)
            x = 0LL;
        else
            x--;
        edge[x].push_back(i);
        //edge[i].push_back(x);
    }
    dfs(0LL, -1LL);
    cout << ans << endl;
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}