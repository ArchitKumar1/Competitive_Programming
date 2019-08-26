#include<bits/stdc++.h>
#pragma GCC optimize("O3","Ofast")
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){return os<<"("<<P.first<<","<<P.second<<")";}
#define DEBUG1(x) cout  << '>' << " " << #x << ':' << " " <<  x << endl;
#define DEBUG2(x,y) cout  << '>' << " " << #x << ':' << " " <<  x <<  " " << #y << ':' << " " <<  y <<endl;
#define DEBUG3(x,y,z) cout  << '>' << " " << #x << ':' << " " <<  x << " " << #y << ':' << " " <<  y <<" " << #z << ':' << " " <<  z << " " <<endl;
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

const int mod = 10*9+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

/////////////////////////////////

const int N = 100;

vector<pair<int,int>> graph[N];
VI par(N);
VI size(N);
VI vis(N, 0);
int n,m;

int cost = 0;
void prims(int s){

    set<pair<int, int>> ss;
    ss.insert({0, s});
    while(!ss.empty()){
        PII temp = *ss.begin();
        ss.erase(ss.begin());
        int u = temp.S;
        if(vis[u] == 1)
            continue;
        cost += temp.F;
        vis[u] = 1;
        for(PII c : graph[u]){
            ss.insert({c.S, c.F});
        }
    }
}
struct edge{
    int u,v,w;
    bool operator< (const edge &b){
        return w < b.w;
    }
};
vector<edge> res, all;

void make(int v){
    par[v] = v;
}
int find(int v){
    if(par[v] == v)
        return v;
    else
        return par[v] = find(par[v]);
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b)
        return;
    if(size[a] < size[b])
        swap(a, b);
    size[a] += size[b];
    par[b] = a;
}
void kruskals(){
    for (int i = 0; i < n;i++){
        make(i);
    }
    sort(ALL(all));
    int p = 0;
    for (edge e : all){
        if( p  == n)
            break;
        if(find(e.u)!= find(e.v)){
            merge(e.u, e.v);
            cost += e.w;
            ++p;
        }
    }
}
void solve(){

    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int x, y, z;
        cin >> x >> y >> z;
        graph[x].PB({y, z});
        graph[y].PB({x, z});
        all.PB({x, y, z});
        all.PB({y, x, z});
    }

    //prims(0);
    kruskals();
    cout << cost << endl;
}
int main()
{
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    //cin >> t;
    while(t--)
        solve();

#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;    
            
}