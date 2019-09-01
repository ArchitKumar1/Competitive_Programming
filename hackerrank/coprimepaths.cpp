#include<bits/stdc++.h>
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){
    os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){
    return os<<"("<<P.first<<","<<P.second<<")";
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
		const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...) 1
#endif

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)

#define ALL(x) x.begin(),x.end()
#define LL long long int
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define endl "\n"

typedef pair<int,int>PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<PII> VPII;

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


const int N = 25 * 1e3  + 100;
vector<int> G[N];
vector<int> val(N,0);
vector<int> tin(N,0),tout(N,0);
vector<int> parent(N,0);
int up[N][20];

int timer= 0;
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v))
        return u;
    if (is_ancestor(v, u))
        return v;
    for (int i = 20; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}

void dfs(int s,int par){
    tin[s] = timer++;
    parent[s] = par;
    for(int c : G[s]){
        if(c!=par){
            dfs(c,s);
        }
    }
    tout[s] = timer++;
}
void findpath(int LCA,int u,int v,vector<int> &path){
    vector<int> t1,t2;
    for(int i = u;i!= LCA;i = parent[i]){
        t1.PB(i);
    }
    for(int i = v;i!=LCA;i = parent[i]){
        t2.PB(i);
    }
    reverse(ALL(t2));
    for(int x : t1){
        path.PB(x);
    }
    path.PB(LCA);
    for(int x : t2){
        path.PB(x);
    }
}
int main(){
FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    int n,q;
    cin >> n >> q;
    forn(i,n) cin >> val[i];
    forn(i,n-1){
        int x,y;
        cin >> x >> y;
        --x;--y;
        G[x].PB(y);
        G[y].PB(x);
    }    
    
    dfs(0,-1);

 
    while(q--){
        int u,v;
        cin >>u >> v;
        u--;v--;
        int LCA = lca(u,v);
        vector<int> path;
        findpath(LCA,u,v,path);
        //trace(path);
        for(int &c : path){
            c = val[c];
        }
        //trace(path);
        int fans= 0 ;
        for(int i=0;i<path.size();i++){
            for(int j = i+1;j<path.size();j++){
                fans += (__gcd(path[i],path[j]) == 1);
            }
        }
        cout << fans << endl;
    }
}