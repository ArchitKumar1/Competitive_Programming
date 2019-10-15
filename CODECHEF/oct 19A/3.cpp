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
#define REP(i,a,b) for(int i = a;i<=b;i++)

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

const int mod = 720720;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////

vector<vector<int>> G;
vector<int> in,out,vis;

int cnt = 0;
void dfs(int s,int par){
    ++cnt;
    vis[s] =1;
    if(in[s]>0){
        in[s]--;
        for(int c : G[s]){
            if(vis[c] == 1) continue;
            dfs(c,s);
        }
    }
    
}   
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    TC{
        int n;
        cin >> n;
        G.assign(n,vector<int>());
        in.assign(n,0);
        out.assign(n,0);

        int m;
        cin >> m;
        for(int i=0;i<n;i++){
            int x,y;
            cin >>x >> y;
            in[x]++;
            in[y]++;
            --x;--y;
            G[x].PB(y);
            G[y].PB(x);
        }
        vector<pair<int,int>> connected;
        for(int i=0;i<n;i++){
            cnt = 0;
            if(vis[i] == 0){
                dfs(i,-1);
            }
            connected.
        }
    }
    return 0;
}




