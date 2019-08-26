#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = 3467;
const ll inf = (ll) 1e18;
int n,m;
vector<pair<int,ll>> edge[N];
vector<ll> dist,mark;
map<pair<int,int>,int> m1;
void dij(int s){
    dist.assign(n,inf);
    mark.assign(n,0);
    dist[s] = 0;
    set<pair<ll,int>> ss;
    ss.insert({0,s});
    while(!ss.empty()){
        pair<ll,int> temp = *ss.begin();
        ss.erase(ss.begin());
        int u = temp.second;
        for(auto c : edge[u]){
            int v = c.first;
            ll w = c.second;
            if(dist[v] > dist[u] + w){
                ss.insert({dist[v] = dist[u] + w,v});
            }
        }
    }
}
                
void solve(){
    cin >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,z;
        cin >> x >> y >> z;
        x--;y--;
        if(m1[{x,y}]){
            if(m1[{x,y}] > z){
                m1[{x,y}] = z;
                m1[{y,x}] = z;
            }
        }else{
            m1[{x,y}] = z;
            m1[{y,x}] = z;
        }
             
    }
    for(auto c : m1){
        int u = c.first.first;
        int v = c.first.second;
        int w = c.second;
        edge[u].push_back({v,w});
    }
    int s ;
    cin >> s;
    dij(--s);
    for(int i=0;i<n;i++){
        if(i == s) continue;
        if(dist[i] == inf){
            cout << "-1 ";
        }else{
            cout << dist[i] << " ";
        }
    }
    cout << endl;
    dist.clear();
    mark.clear();
    m1.clear();
    for(int i=0;i<n;i++){
       edge[i].clear();
    }
                
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
    