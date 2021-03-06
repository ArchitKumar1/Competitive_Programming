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

typedef pair<int,int>PII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VL;
typedef vector<VL> VLL;
typedef pair<LL,LL>PLL;
typedef vector<PLL> VPLL;
 
const int mod = pow(10,9)+7;
const double inf = 1e18;
const LL linf = 2e18;
const double eps = 1e-9;
const int LOGN = 20;
//////////////////////////////////////////////

int n1,n2,K1,K2;

int dp[101][101][11][11];

int solve(int i,int j,int k1,int k2){
    if(dp[i][j][k1][k2] != -1) return dp[i][j][k1][k2];
    if(i == n1 && j == n2) {
        return dp[i][j][k1][k2] = 1;
    }
    int ans = 0;
    if(i+1<=n1){
        if(k1+1<=K1) (ans += solve(i+1,j,k1+1,0))%=mod;
    }
    if(j+1<=n2){
        if(k2+1<=K2) (ans += solve(i,j+1,0,k2+1))%=mod;
    }
    return dp[i][j][k1][k2] = ans;

}



int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
TC{
    memset(dp,-1,sizeof(dp));
    cin >> n1 >> n2 >> K1 >> K2;
    cout << solve(0,0,0,0) << endl;
}
#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}