#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 12345;
vector<int> e[N];
const int L = 20;
int up[N][L];
int timer = 0;
vector<int> in(N), out(N);

void dfs(int s ,int par){
    up[s][0] = par;
    in[s] = ++timer;
    for (int i = 1; i < L;i++){
        up[s][i] = up[up[s][i - 1]][i - 1];
    }
    for (auto c : e[s]){
        if(c!= par)
            dfs(c, s);
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
    
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(0, -1);
    cout << lca(2, 3) << endl;

    for (int i = 0; i < n;i++){
        cout << i << " : ";
        for (int j = 0; j < L;j++){
            cout << up[i][j] << " ";
        }
        cout << endl;
    }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}