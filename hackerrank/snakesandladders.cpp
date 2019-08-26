#include<bits/stdc++.h>
using namespace std;
const int N = 105;

vector<int> e[N];
const int inf = 1e9;
map<int, int> ss, ll;
vector<int> mark, dist;

void dij(int s){
    dist.assign(N, inf);
    mark.assign(N, 0);

    set<pair<int, int>> se;
    se.insert({0, s});
    dist[s] = 0;
    while(!se.empty()){
        pair<int, int> temp = *se.begin();
        se.erase(se.begin());
        int u = temp.second;
        if(mark[u]) continue;
        mark[u] = 1;
        for(int v : e[u]){
            if(dist[v] > dist[u] + 1){
                se.insert({dist[v] = dist[u] + 1, v});
            }
        }
    }
}
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x, y;
        cin >> x >> y;
        ll[x] = y;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m;i++){
        int x, y;
        cin >> x >> y;
        ss[x] = y;
    }

    for (int i = 1; i <= 100;i++){
        for (int j = 1; j <= 6;j++){
            if(i+j <= 100){
                if( ll[i + j]){
                    int u = i;
                    int v = ll[i + j];
                    e[u].push_back(v);
                }else if(ss[i + j]){
                    int u = i;
                    int v = ss[i + j];
                    e[u].push_back(v);
                }else{
                    int u = i;
                    int v = i + j;
                    e[u].push_back(v);
                }
            }  
        }
    }
    dij(1);
    (dist[100] == inf) ? cout << "-1" : cout << dist[100];
    dist.clear();
    mark.clear();
    ll.clear();
    ss.clear();
    for (int i = 0;i<105;i++){
        e[i].clear();
    }
    cout << endl;
    
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}