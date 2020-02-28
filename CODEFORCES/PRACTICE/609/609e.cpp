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
#define ALL(x) x.begin(),x.end()
#define LL long long int
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define endl "\n"
#define l() cout << endl;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)

typedef pair<int,int>PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VL;
typedef vector<VL> VLL;
typedef pair<LL,LL>PLL;
typedef vector<PLL> VPLL;
 
const int mod = pow(10,9)+7;
const double inf = 1e18;
const LL linf = 2e18;
const double eps = 1e-9;
const int LOGN = 20;
//////////////////////////////////////////////

LL mul(LL a,LL b){
    LL ans = (a*b)%mod;
    return ans;
}
LL add(LL a,LL b){
    return (a+b)%mod;
}
LL pow(LL a,LL b,LL mod){
    LL res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        a = ((LL)a*a)%mod;
        b>>=1;
    }
    return res;
}

const int N = 2.1e5;
struct edge{
    int u,v,cost;
    bool operator< (const edge &e){
        return cost < e.cost;
    }
};
vector<int> par(N,0);
int find(int v){
    return (par[v] == v) ? v : par[v] = find(par[v]);
}
void merge(int a,int b){
    a = find(a);b= find(b);
    if(a == b) return;
    par[a] = b;
}

vector<edge> mst,all,old;
vector<vector<PII>> G(N);
vector<int> depth(N,0);
vector<vector<int>> me(N,vector<int>(LOGN,0));
vector<vector<int>> p(N,vector<int>(LOGN,1));
set<pair<int,int>> s;
LL total_cost  =0;

void dfs(int s,int par){
    depth[s] = depth[par] + 1;
    p[s][0] = par; 
    for(PII c : G[s]){    
        if(c.F == par) continue;
        me[c.F][0] = c.S;
        dfs(c.F,s);
    }
}
int lca(int u,int v) {
	if (depth[u]>depth[v]) swap(u,v);
	for(int i = LOGN-1;i>=0;i--) if (depth[p[v][i]]>=depth[u]) v=p[v][i];
	if (u==v) return u;
	for(int i = LOGN-1;i>=0;i--) if (p[v][i]!=p[u][i]) u=p[u][i],v=p[v][i];
	return p[u][0];
}
int gmax(int l,int u){
    int maxi = 0;
    for(int i = LOGN-1;i>=0;i--) if (depth[p[u][i]]>=depth[l]) {
        maxi = max(maxi,me[u][i]);
        u = p[u][i];
    }
    return maxi;
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
   FASTIO
    int n,m;
    cin >> n >> m;
    edge e;
    forn(i,m){
        cin >> e.u >> e.v >> e.cost;
        all.PB(e);
    }
    old = all;
    sort(ALL(all));
    
    forn(i,N) par[i] = i;
    forn(i,m){
        if(find(all[i].u) != find(all[i].v)){
            merge(all[i].u,all[i].v);
            mst.PB(all[i]);
            total_cost += all[i].cost;
        }
    }
    for(edge e : mst){
        G[e.u].PB({e.v,e.cost});
        G[e.v].PB({e.u,e.cost});
        s.insert({e.u,e.v});
    }
    dfs(1,1);
    for(int j =1;j<LOGN;j++){
        for(int i = 1;i<=n;i++){
            p[i][j] = p[p[i][j-1]][j-1];
            me[i][j] = max(me[i][j-1],me[p[i][j-1]][j-1]);
        }
    }
    // trace(total_cost);
    // for(int i = 1;i<=n;i++){
    //     for(int j = 0;j<LOGN;j++){
    //         cout << p[i][j];
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(int i = 1;i<=n;i++){
    //     for(int j = 0;j<LOGN;j++){
    //         cout << me[i][j];
    //     }
    //     cout << endl;
    // }
    // for(PII p : s){
    //     trace(p);
    // }
    for(edge e : old){
        if(s.find({e.u,e.v}) != s.end()){
            cout << total_cost << endl;
        }else{
            int LCA = lca(e.u,e.v);
            int MAXI = max(gmax(LCA,e.u),gmax(LCA,e.v));
            cout << total_cost + e.cost - MAXI << endl;
        }
    }

#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}