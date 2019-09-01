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

int cost[4][4];

vector<int> dp(16,inf);
string bin(int i){
    string ans = "";
    while(i){
        ans += (i%2 ? "1" : "0");
        i >>= 1;
    }

    reverse(ALL(ans));
    return ans;
}
int main(){
FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    forn(i,4)forn(j,4) cin >> cost[i][j];

    dp[0]=  0;
    for(int i=0;i<16;i++){
        int x = __builtin_popcount(i);
        for(int j=0;j<4;j++){
            if( not(i & (1 << j))){
                //trace(bin(i),bin(j),dp[i | (1 << j)],dp[i],dp[i] + cost[x][j]);
                dp[i | (1 << j)] = min(dp[i | (1 << j)],dp[i] + cost[x][j]);
                
            }
        }
    }
    cout << dp[15] << endl;

    // 1 2 3 78888
    // 2 3 4 45555
    // 4 5 6 25552
    // 3 3 4 100000

}