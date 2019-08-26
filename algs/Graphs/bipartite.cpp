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

const int N = 3e3;
vector<int> graph[N];
int n,m;
int cnt = 1;
int bipartite(){
    VI color(n,0);
    int bi = 1;
    for (int i = 0; i < n;i++){
        if(colmpty()){
                int u = ll.front();
                ll.pop_front();
                for(int v : or[i] == 0){
            color[i] = 1;
            list<int> ll;
            ll.PB(i);
            while(!ll.egraph[u]){
                    if(color[v] == 0){
                        //DEBUG2(u, v);
                        color[v] = color[u] == 1 ? 2 : 1;
                        ll.PB(v);
                    }else{
                        bi &= color[u] != color[v];
                    }
                }
            }
        }
    }
    return bi;
}
void solve(){
    cin >> n >> m;
    forn(i,m){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        graph[x].PB(y);
        graph[y].PB(x);
    }
    cout << "Scenario #" << cnt++ << endl;
    cout << (!bipartite()? "Suspicious bugs found!"  : "No suspicious bugs found!") << endl;
    for (int i = 0; i < n;i++){
        graph[i].clear();
    }
}
int main()
{
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while(t--)
        solve();

#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;    
            
}