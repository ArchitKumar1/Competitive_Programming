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

const int mod = pow(10,9)+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

/////////////////////////////


const int N = 1234;
vector<pair<PII,PII>> G[N];
vector<int> vis(N,0),dist(N,inf),tim(N,0);
vector<int> par(N,0);
int k,n,m,s,d;

void dij(){
    int k=1000;
    dist[s] = 0;
    set<PII> ss;
    ss.insert({0,s});
    while(ss.size()){
        PII temp = *ss.begin();ss.erase(ss.begin());
        int u = temp.S;
        //if(vis[u]) continue; vis[u] =1;
        for(auto x : G[u]){
            int v = x.F.S;
            int t = x.S.F;
            int c = x.S.S;
            if(dist[v] > dist[u] +c + k*(t)){
                dist[v] = dist[u] +c + (k)*(t);
                // DEBUG3(v,u,dist[u]);
                // DEBUG3(c,t,dist[v]);
                par[v] = u;
                ss.insert({dist[v],v});
                //DEBUG3(c,t,dist[v]);
            }
        }
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    cin >> k >> n >> m;
    for(int i=0;i<m;i++){
        int x,y,t,c;
        cin >>x >> y >> t >> c;
        --x;--y;
        G[x].PB({{x,y},{t,c}});
    }
    cin >>s >> d;
    --s;--d;
    dij();
    // for(int i=0;i<n;i++){
    //     cout << dist[i] << " ";
    // }
    vector<int> path;
    int nodes = 1;
    for(int i = d;i!=s;i = par[i] ){
        ++nodes;
        path.PB(i+1);
    }
    path.PB(s+1);
    reverse(ALL(path));

    if(dist[d] >=inf){
        cout << "Error" << endl;
    }else{
        for(int i=0;i<path.size();i++){
            cout << path[i];
            if(i!= path.size()-1) cout << "->";
        }
        cout << " " << nodes <<  " ";
        cout << dist[d] + k*(nodes-1);
    }
}