#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = 123456;
const ll inf = 1e18;

vector<ll> dist, mark,par;
vector<pair<ll, ll>> edge[N];

void dij(ll n,ll s ){
    dist.assign(n, inf);
    mark.assign(n,0LL);
    par.assign(n,-1LL);
    set<pair<ll, ll>> m1;
    m1.insert(make_pair(0, s));
    dist[s] = 0;
    while(!m1.empty()){
        pair<ll, ll> temp = *m1.begin();
        m1.erase(m1.begin());
        ll u = temp.second;
        if(mark[u]) continue;
        mark[u] = 1;
        for(auto c: edge[u]){
            ll v = c.first;
            ll w = c.second;
            if(dist[v] > dist[u] + w){
                m1.insert(make_pair(dist[v] = dist[u] + w, v));
                par[v] = u;
            }
        }
    }
}
void solve(){
    ll n;
    cin >> n;
    ll m;
    cin >> m;

    for(ll i=0;i<m;i++){
        ll u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edge[u].push_back(make_pair(v, w));
        edge[v].push_back(make_pair(u, w));
    }
    ll s = 0LL;
    dij(n,s );

    
    vector<ll> ans;
    for (ll i = n - 1LL; i != -1LL;i = par[i]){
        ans.push_back(i);
    }
    reverse(ans.begin(), ans.end());
    if(*ans.begin()!= 0 && *ans.end()!= n-1){
        cout << -1 << endl;
    }
    else{
        for(ll x : ans){
            cout << x + 1 << " ";
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
    solve();

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}