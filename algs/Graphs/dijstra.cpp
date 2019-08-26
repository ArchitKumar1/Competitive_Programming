#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb(x) push_back(x)
using namespace std;
const int inf = 1 << 28;
const ll N = 1e6;
vector<pair<ll, ll>> e[N];
vector<ll> dist;
vector<ll> mark;
void dij(ll s ,ll n ){
    dist[s] = 0LL;
    multiset<pair<ll, ll>> pq;
    pq.insert({0LL, s});
    while(!pq.empty()){
        pair<ll, ll> temp = *pq.begin();
        pq.erase(pq.begin());
        ll u = temp.second;
        if(mark[u]) continue;
        mark[u] = 1LL;
        for(auto c : e[u]){
            ll v = c.first;
            ll w = c.second;
            if(dist[v]> dist[u] + w){
                dist[v] = dist[u] + w;
                pq.insert({dist[v], v});
            }
        }
    }
}
int main()
{
    fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ll n,m;
    cin >> n >> m;
    dist.assign(n + 1LL, inf);
    mark.assign(n + 1LL, false);
    for (ll i = 0LL; i < m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    ll z;
    cin >> z;
    while(z--) {
        ll x;
        cin >> x;
        e[0LL].push_back({x,0LL});
        e[x].push_back({0LL,0LL});
    }
    dij(0LL,n);

    for (ll i = 1LL; i <= n;i++){
        cout << dist[i] << "\n";
    }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
