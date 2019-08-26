#include<bits/stdc++.h>
using namespace std;

const int N = 1010;
vector<int> g[N];
int vis[N],low[N],tin[N],cut[N];
int timer = 0;
int ap = 0;
set<pair<int,int>> bridges;
void dfs(int s, int par){
    vis[s] = 1;
    tin[s] = low[s] = timer++;
    int child = 0;
    for(auto c: g[s]){
        if( c == par) continue;
        if(vis[c]){
            low[s] = min(low[s],tin[c]);
        }else{
            dfs(c,s);
            low[s] = min(low[s],low[c]);
            if(low[c] >= tin[s] && par!=-1){
                cut[s] = 1;
                ap++;
            }
            ++child;
            if(low[c] > tin[s]){
                if(s>c) (s,c);    
                bridges.insert({s,c});
            }
        }
    }
    if(par == -1 && child >1) {cut[s] = 1;ap++;}
}
               
void solve(){
    int n; cin >> n; int m; cin >> m;
    int p;
    cin >> p;
    for(int i=0;i<m;i++){
        int x,y; cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    fill(vis,vis+n,0);
    fill(low,low+n,0);
    dfs(0,-1);
    cout <<endl << bridges.size() << endl;
    
          
}
            
int main(){
   ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}