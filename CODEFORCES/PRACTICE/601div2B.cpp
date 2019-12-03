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

const int N =3e5;

vector<vector<int>> G(N);
map<pair<int,int>,pair<double,double>> m1;
vector<double> dp(N,0) ;

void dfs(int s,int par){
    for(int c : G[s]){
        if(c == par) continue;
        dfs(c,s);
        dp[s] +=  m1[{c,s}].S * dp[c] + m1[{c,s}].S * m1[{c,s}].F;
    }
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    cout << setprecision(10);
    cout << fixed;
    int n;
    cin >> n;
    forn(i,n-1){
        int x,y;
        double d,p;
        cin >> x >> y >> d >> p;
        x--;y--;
        G[x].PB(y);G[y].PB(x);
        m1[{x,y}] = {d,p};
        m1[{y,x}] = {d,p};
    }
    dfs(0,-1);
    cout << dp[0] << endl;

#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}