#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pii> vpii;
typedef vector<vi> vvi;

const int N = 100000;
vpii g[N];
bool vis[N];
vi res;

bool dfs(int s){
    vis[s] = 1;
    bool ret = false;
    for(auto c: g[s]){
        int x = c.first;
        int state  = c.second;
        if(vis[x]) continue;

        bool add = dfs(x);
        if(state == 2 && !add){
            res.push_back(x);
            ret = true;
        }
        if(add)
            ret = true;
    }
    return ret;
}

int main(){
    //fastio    
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n-1;i++){
        int x, y, z;
        cin >> x >> y >> z;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }
    
    dfs(1);
    cout << res.size() << endl;
    for(int v : res)
        cout << v << " ";
#ifndef ONLINE_JUDGE
		cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}