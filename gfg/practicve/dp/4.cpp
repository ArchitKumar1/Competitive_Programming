#include<bits/stdc++.h>
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

struct edge{
    int u,v,w;
    bool operator < (const edge &a ){
        return w < a.w;
    }
};


vector<edge> all;
vector<int> dist,path;

int main(){
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int m;
    cin >> m;
    int s,d;
    cin >>s >> d;
    --s;--d;
    forn(i,m){
        int x,y,z;
        cin >> x>> y >> z;
        --x;--y;
        all.PB({x,y,z});
    }

    dist.assign(n,inf);
    path.assign(n,0);
    dist[s] = 0;
    for(;;){
        bool any = 0;
        for(auto e : all){
            int u = e.u;
            int v = e.v;
            int w = e.w;
            if(dist[u]!= inf){               
                if(dist[v] > dist[u] + w){
                    dist[v]  =dist[u] + w;
                    path[v] = u;
                    DEBUG3(u,v,path[v]);
                    any = 1;
                }
            }
        }
        if(!any) break;
    }
    
    cout << dist[d] << endl;
    for(int i=0;i<n;i++){
        DEBUG3(i+1,dist[i],path[i]);
        
    }
    vector<int> path;
    for(int i = d;i != s;i = path[i]){
        path.PB(i + 1);
    }
    path.PB(s+1);
    reverse(ALL(path));
    cout << path;



}