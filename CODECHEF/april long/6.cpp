#include<bits/stdc++.h>
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

const int N = 250000;
vector<ll> e[N];
vector<ll> v, dp, mark;

ll n,z;

void dfs(ll s,ll par){
	ll sum = v[s];
	for (auto c : e[s]){
		if(c == par) continue;
		dfs(c, s);
		sum += dp[c];
	}
	dp[s] = max(-z, sum);
}
int main()
{
    fastio
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

ll t;
cin >> t;
while(t--){

	cin >> n >> z;
	v.assign(n,0LL);
	dp.assign(n,0LL);
	for (ll i = 0LL; i < n;i++){
		cin >> v[i];
	}
	for (ll i = 0LL; i < n - 1LL;i++){
		ll x, y;
		cin >> x >> y;
		x--;y--;
		e[x].push_back(y);
		e[y].push_back(x);
	}
	dfs(0LL, -1LL);
	cout << max(dp[0], -z) << endl;
	for (int i = 0; i < n;i++){
		e[i].clear();
	}
}
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}
