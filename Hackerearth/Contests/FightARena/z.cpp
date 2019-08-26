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

const int mod = pow(10,9)+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


const int N = 1234;
vector<int> G[N];
vector<int> val[N];
vector<int> vis(N,0);
int risk[N];

int total = 0;
vector<int> tempval;

void dfs(int s){
    vis[s] = 1;
    tempval.PB(risk[s]);
    for(int c: G[s]){
        if(vis[c] == 0){
            dfs(c);
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    int n;
    cin >> n;
    forn(i,n) cin >> risk[i];

    int m;
    cin >> m;
    forn(i,m){
        int x,y;
        cin >> x >> y;
        --x;--y;
        G[x].PB(y);
        G[y].PB(x);
    }
    for(int i=0;i<n;i++){
        if(vis[i] == 0){
            tempval.clear();
            dfs(i);
            val[total++] = tempval;
        }  
    }
    int fans =1;
    int mincost = 0;
    for(int i=0;i<total;i++){
        vector<int> curr = val[i];
        if(curr.size() == 1){
            fans = fans*1;
            mincost += curr[0];
        }else{
            int cnt = 0;
            int mine = *min_element(ALL(curr));
            for(int yy : curr){
                if(yy == mine){
                    cnt++;
                }
            }
            fans *= cnt;
            fans %= mod;
            mincost += mine;
        }
    }
    cout << fans << endl;
}