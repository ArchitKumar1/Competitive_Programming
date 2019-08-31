#include<bits/stdc++.h>
using namespace std;
#include<stdio.h>
#include <unistd.h>
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

VVI g;
VI in,out,val;
VPII max2;
int fans = INT_MIN;

void dfs1(int s,int par){
    int m = 0;
    vector<int> all()
    for(int c : g[s]){
        if(c == par) continue;
        dfs1(c,s);
        m = max(m,in[c]);
    }
    in[s] = val[s] + m; 
}

void dfs2(int s,int par){
    
    for(int c : g[s]){
        if(c == par) continue;
        dfs2(c,s);
        m = max(m,in[c]);
    } 
}
int main(){
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    g.resize(n);
    in.resize(n);
    out.resize(n);
    val.resize(n);
    max2.resize(n);
    forn(i,n) cin >> val[i];
    forn(i,n-1) {
        int x,y; cin >> x>> y; --x;--y; g[x].PB(y) ;G[y].PB(x);
    }
    dfs1(0,-1);
    dfs2(0,-1);
    cout << fans  << endl;
    cout << "OK";


}