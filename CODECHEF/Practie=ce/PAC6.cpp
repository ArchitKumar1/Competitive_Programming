#include<bits/stdc++.h>
using namespace std;
#define ll  long long int
const ll inf = (ll)1e15;
const ll N = 12345;
vector<pair<ll,ll>> e[N];
vector<ll> mark;
vector<ll> dist;



void dij(int x,int n){
    mark.assign(n, 0LL);
    dist.assign(n, inf);
    multiset<pair<ll, ll>> ms;
    dist[x] = 0;
    ms.insert({0LL, x});
    while(!ms.empty()){
        pair<ll, ll> p = *ms.begin();
        ms.erase(ms.begin());
        ll u = p.second;
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
    ll n,m,r,x,y;
    cin >> n >> m >> r >> x >> y;
    x--;
    y--;
    for (ll i = 0LL; i < r;i++){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;
        b--;
        e[a].push_back({b, c});
        e[b].push_back({a, c});
    }

    dij(x, n);
    
    if(dist[y] <= m){
        cout << "alive " << dist[y] << endl;
    }else{
        cout << "died" << endl;
    }
}