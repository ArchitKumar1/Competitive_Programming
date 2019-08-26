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

const int mod = 1000 * 1000 *1000+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

/////////////////////////////

vector<vector<int>> g;
vector<int> vis,all;

int n, m;

void dfs(int s,int &cnt){
    cnt++;
    vis[s] = 1;
    for(int c : g[s]){
        if(vis[c] == 0){           
            dfs(c,cnt);
        }
    }
}
void solve(){
    cin >> n >> m;
    g.assign(n, vector<int>());
    for (int i = 0; i < m;i++){
        int x, y;
        cin >> x >> y;
        --x;--y;
        g[x].PB(y);
        g[y].PB(x);
    }
    int num = 0;
    vis.assign(n, 0);
    all.clear();
    int cnt = 0;
    for (int i = 0; i < n;i++){
        if(vis[i] == 0){
            ++num;
            cnt = 0;
            dfs(i,cnt);
            all.PB(cnt);
        }
    }
    long long fans = 1;
    for(int xx : all){
        fans = fans * (long long) xx;
        fans %= mod;
    }
    cout <<num <<  " " << fans << endl;
    
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    TC{       
        solve();
    }
#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
}