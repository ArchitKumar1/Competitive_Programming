#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 113456LL;
vector<ll> e[N];
vector<ll> v(N), m(N),hcf(N);

void dfs(ll s,ll par){
	if(s == 0){
		hcf[s] = v[s];
	}else{
		hcf[s] = __gcd(hcf[par], v[s]);
	}
	for(auto c: e[s]){
		if(c == par) continue;
		dfs(c, s);
	}
}
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
		int n;
		cin >> n;
		for (int i = 0LL; i < n - 1LL;i++){
			int x, y;
			cin >> x >> y;
			x--;y--;
			e[x].push_back(y);
			e[y].push_back(x);
		}
		for (int i = 0LL; i < n;i++){
			cin >> v[i];
		}
		for (int i = 0; i < n;i++){
			cin >> m[i];
		}
		dfs(0LL, -1LL);
		for (int i = 1LL; i < n;i++){
			if(e[i].size() == 1LL){
				cout << m[i] - __gcd(m[i],hcf[i]) << " ";
			}
		}
		for (int i = 0LL; i < n; i++){
			e[i].clear();
			v[i] = 0;
			m[i] = 0;
		}
	}
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}