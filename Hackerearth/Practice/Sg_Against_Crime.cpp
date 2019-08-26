#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<cstdio>

#define gc getchar
using namespace std;

const int N = 100005;
vector<int> g[N];
int vis[N],low[N],tin[N],cut[N];
int timer = 0;

unordered_map<int,string> m1;
unordered_map<int,string> m2;
unordered_map<string,int> bridges;

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
            ++child;
            if(low[c] > tin[s]){
                string temp = to_string(c) + "?" + to_string(s);
                bridges.insert({temp,1});
            }
        }
    }
}

                  
void solve(){
    int n; cin >> n; int m; cin >> m; int q; cin >> q;
    for(int i=0;i<m;i++){
        int x,y,z; cin >> x >> y >> z ;x--;y--;
        g[x].push_back(y);
        g[y].push_back(x);
        string a = to_string(x) + "?" + to_string(y);
        string b = to_string(y) + "?" + to_string(x);
        m1[z] = a;
        m2[z] = b;
    }
    fill(low,low+n,-1);
    fill(tin,tin+n,-1);
    timer = 1;
    for(int i=0;i<n;i++){
        if(!vis[i]) dfs(i,-1);
    }
    while(q--){
        int x ;
        cin >> x;
        if(bridges.find(m1[x]) != bridges.end())
            cout << "YES" << "\n";
        else if(bridges.find(m2[x]) != bridges.end())
            cout << "YES" << "\n";
        else cout << "no" << "\n";
    }
}
            
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    solve();
    return 0;
}