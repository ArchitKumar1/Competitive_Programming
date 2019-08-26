#include<bits/stdc++.h>
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

const ll N = 210000LL;
const ll inf = (ll) 1 << 30;
vector<ll> e[N];
vector<ll> w(N),parent(N);

ll maxn1 = 0LL;
ll maxn2 = inf;

void dfs1(ll s ,ll par){
    parent[s] = par;
    for(auto kid : e[s]){
        if(kid == par ){
            continue;
        }
        dfs1(kid, s);
    }
}
void dfs2(ll s ,ll par,ll k){
    ll temp = w[s] ^ k;
    
    if(temp > maxn1){
        maxn1 = temp;
        maxn2 = s;
    }
    else if(temp == maxn1){
        maxn2 = min(maxn2, s);
    }
    for(auto c: e[s]){
        if(c == par) continue;
        dfs2(c, s, k);
    }
}
int main(){
    fastio
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

int t;
cin >> t;
while(t--){
    ll n,q;
    cin >> n >> q;
    for (ll i = 0LL; i < n;i++){
        cin >> w[i];
    }

    for (ll i = 0LL; i < n-1LL;i++){
        ll x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs1(0LL, -1LL);
    
    ll aa = 0LL, bb = 0LL;
    for (ll i = 0LL; i < q;i++){
        maxn1 = 0LL;
        maxn2 = inf;
        ll x, y;
        cin >> x >> y;
        x = x ^ aa;
        y = y ^ bb;
        x--;
        dfs2(x, parent[x], y);
        ll x1, y1;
        x1 = maxn2 + 1LL;
        y1 = maxn1;
        cout << x1 << " " << y1 << endl;
        aa = x1;
        bb = y1;
    }

    for (int i = 0LL; i < n;i++){
        e[i].clear();
    }
    w.clear();
    parent.clear();
}


}