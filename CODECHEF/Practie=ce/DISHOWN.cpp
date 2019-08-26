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

/////////////////////////////

const int N = 123456;
vector<pair<int, int>> g2[N];
vector<int> size, cost, C,pare,g[N];
int totalcost = 0;

void prims(int s){
    vector<int> vis(N, 0);
    set<pair<int, int>> ss;
    ss.insert({0, s});
    while(ss.size()){
        PII temp = *ss.begin();
        ss.erase(ss.begin());
        int d = temp.first;
        int u = temp.second;
        if(vis[u] == 1)
            continue;
        vis[u] = 1;
        totalcost += d;
        for (PII c : g2[u]){
            ss.insert({c.second, c.first});
        }
    }
}
void make(int v){
    pare[v] = v;
    size[v] = 1;
    cost[v] = C[v];
}
int find(int v){
    if(v == pare[v])
        return v;
    else
        return pare[v] = find(pare[v]);
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(size[a] <size[b])
            swap(a, b);
        size[a] += size[b];
        if(cost[a] * cost[b] >=0){
            cost[a] = min(cost[a], cost[b]);
        }else{
            if(cost[a] < 0){
                cost[a] = cost[b];
            }else{
                cost[a] = cost[a];
            }
        }
        pare[b] = a;
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin >> n >> m;
    size.assign(n, 0);
    cost.assign(n, 0);
    C.assign(n, 0);
    pare.assign(n, 0);

    forn(i,m){
        int x,y;
        cin >> x >> y;
        --x;--y;
        g[x].PB(y);
        g[y].PB(x);
    }
    for (int i = 0; i < n;i++){
        cin >> C[i];
        make(i);
    }
    for(int i=0;i<n;i++){
        for(int x : g[i]){
            merge(x, i);
        }
    }
    int num_cc = 0;
    map<int, int> m1;
    vector<int> comps;
    for (int i = 0; i < n;i++){
        int par= find(i);
        if(m1[par] == 1){
            continue;
        }else{
            ++num_cc;
            comps.PB(par);
            m1[par] = 1;
        }
    }
    bool ok = 1;
    for(int i=0;i<num_cc;i++){
        if(cost[comps[i]]<0 ){
            ok = 0;
        }
    }
    if(ok == 0){
        cout << "-1" << endl;
    }else{
        for (int i = 0; i < num_cc;i++){
            for (int j = i+1; j < num_cc;j++){
                if(i == j) continue;
                g2[i].PB({j, cost[comps[i]] + cost[comps[j]]});
                g2[j].PB({i, cost[comps[i]] + cost[comps[j]]});
            }
        }
        prims(comps[0]);
        cout << totalcost << endl;
    }
    return 0;
}