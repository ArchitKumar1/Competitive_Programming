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


int main(){
FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    
    int n;
    cin >> n;
    int W;
    cin >> W;
    vector<int> prices(n+1,0),weight(n+1,0);
    forn(i,n) cin >> prices[i+1];
    forn(i,n) cin >> weight[i+1];
    
    int dp[n+1][W+1];

    for(int i=0;i<=n;i++){
        for(int j = 0;j<=W;j++){
            if(i == 0 || j == 0){
                dp[i][j] = 0;
            }else{
                //trace(j,weight[i]);
                if(j - weight[i] >=0 ){
                    dp[i][j] = max(dp[i-1][j] ,dp[i-1][j-weight[i]] + prices[i]);
                }else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }
    cout << dp[n][W] << endl;
    for(int i=0;i<=n;i++){
        for(int j= 0 ;j<=W;j++){
            cout << dp[i][j] << " ";
        }cout << endl;
    }
    cout << "OK3" << endl;


    //input
    // 4 7
    // 10 20 30 40
    // 1 2 3 8
}