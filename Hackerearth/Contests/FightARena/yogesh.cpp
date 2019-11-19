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

const int mod = pow(10,9)+7;
const double inf = 1e18;
const LL linf = 2e18;
const double eps = 1e-9;

//////////////////////////////////////////////
const int N = 123;
int g[N][N],vis[N][N];
int n,m,x1,y1,x2,y2;

inline bool safe(int i,int j){
    return (i>=0 && j>=0 && i<n && j<m);
}

void dfs(int i,int j,int val){
    if(!safe(i,j)) return ;
    if(val >= g[i][j]) return;
    if(vis[i][j] == 1) return;
    vis[i][j] = 1;
    dfs(i+1,j,g[i][j]);
    dfs(i-1,j,g[i][j]);
    dfs(i,j+1,g[i][j]);
    dfs(i,j-1,g[i][j]);
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
TC{
   cin >> n >> m >> x1 >> y1 >> x2 >> y2;
   x1--,y1--,x2--,y2--;
   memset(vis,0,sizeof(vis));
   forn(i,n)forn(j,m) cin >> g[i][j];
   dfs(x1,y1,-1);

   cout << (vis[x2][y2] ? "YES" : "NO") << endl;
}
   

}