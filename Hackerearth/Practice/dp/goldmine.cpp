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

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////
const int N = 505;
const int K = 12;
int dp[N][N][K][K];
string x,y;
int n,m;

int solve(int i,int j,int k1,int k2){
    if(i == n || j == m ) return 0;
    int ans = 0;
    if(dp[i][j][k1][k2] !=-1) return dp[i][j][k1][k2];
    if(x[i] == y[j]){
        ans = 1 + solve(i+1,j+1,k1,k2);
    }
    else{
        //int ans = 0;
        if (k1 > 0){
            ans = max(ans,1+solve(i+1,j+1,k1-1,k2));
        }
        if(k2>0){
            ans = max(ans,1+solve(i+1,j+1,k1,k2-1));
        }
        ans = max(ans,solve(i+1,j,k1,k2));
        ans = max(ans,solve(i,j+1,k1,k2));
    }
    return dp[i][j][k1][k2] = ans;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    FASTIO
    memset(dp,-1,sizeof(dp));
    cin >> x>> y;
    n = x.length();
    m = y.length();
    int k1,k2;
    cin >> k1 >> k2;
    cout << solve(0,0,k1,k2);
    return 0;
}




