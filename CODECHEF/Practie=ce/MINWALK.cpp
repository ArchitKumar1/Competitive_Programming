#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
const ll inf = (ll)1e15;
const ll N = 12345LL;
vector<pair<int,int>> e[N];
ll dist1[N],dist2[N],dist3[N],mark[N];

void dij(ll x,ll n,ll dist[]){
    fill(mark, mark + n, 0LL);
    fill(dist, dist + n, inf);
    multiset<pair<ll, ll>> ms;
    dist[x] = 0LL;
    ms.insert({0LL, x});
    while(!ms.empty()){
        pair<ll, ll> p = *ms.begin();
        ms.erase(ms.begin());
        ll u = p.second;
        if(mark[u]) continue;
        mark[u] = 1LL;
        for(auto c : e[u]){
            ll v = c.first;
            ll w = c.second;
            if(dist[v] > dist[u] + w){
                ms.insert({dist[v] = dist[u] + w, v});
            }
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

int t;
cin >> t;
while(t--){

    ll n, m;
    cin >> n >> m;
    for (int i = 0; i < n;i++){
        e[i].clear();
    }
        ll s, t, v;
    cin >> s >> t >> v;
    s--;
    t--;
    v--;
    for (ll i = 0LL; i < m;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }
    dij(v, n,dist1);
    dij(s, n,dist2);
    dij(t, n,dist3);
    ll ans = inf;
    for (ll i = 0LL; i < n;i++){
        ans = min(ans, dist1[i] + dist2[i] + dist3[i]);
    }
    cout << ans << endl;
}
    return 0;
}