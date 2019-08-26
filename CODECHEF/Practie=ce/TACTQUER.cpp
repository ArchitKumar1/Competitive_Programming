#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1234567;
vector<pair<int,int>> e[N];
const int L = 35;
int up[N][L];
int timer = 0;
int dist[N];
vector<int> in(N), out(N);

void dfs(int s ,int par,int w){
    if(s == 0) dist[s] = 0; 
    else dist[s] = dist[par] + w;
    up[s][0] = par;
    in[s] = ++timer;
    for (int i = 1; i < L;i++){
        up[s][i] = up[up[s][i - 1]][i - 1];
    }
    for (auto c : e[s]){
        if(c.first == par) continue;
        dfs(c.first, s,c.second);
    }
    out[s] = ++timer;
}

int findlca(int u,int v){
    return in[u] <= in[v] && out[v] <= out[u];
}
int lca(int u,int v){
    if(findlca(u,v))
        return u;
    if(findlca(v,u))
        return v;
    
    for (int i = 0; i < L;i++){
        if(!findlca(up[u][i],v)){
            u = up[u][i];
        }
    }
    return up[u][0];
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    
    int n,m;
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int x, y,z;
        cin >> x >> y >> z;
        x--;y--;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
        
    }
    dfs(0, -1,0);
    
    int q;
    cin >> q;
    while(q--){
        int x, y;
        cin >> x >> y;
        x--;y--;
        int l = lca(x, y);
        int len = dist[x] + dist[y] - 2 * dist[l];
        cout << len << endl;
    }
    
        

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}