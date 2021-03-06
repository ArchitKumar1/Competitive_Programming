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
 
 
/////////////////////////////
 

int main(){
 
FASTIO    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    int t;
    cin >> t;
    while(t--){
        LL n;
         cin >> n;
        LL arr[2*n];
        forn(i,n)  cin >> arr[i];
        forn(i,n) arr[i+n] = arr[i];

        LL m = 2*n;
        LL dp[m][m];
        LL presum[2*n+1];
        presum[0] = 0;
        for(int i=1;i<=2*n;i++){
            presum[i] = presum[i-1] + arr[i-1];
        }
        memset(dp,0,sizeof(dp));
        for(int l = 0;l<m;l++){
            for(int i = 0;i+l<m;i++){
                int j = i+l;
                if(i == j){
                    dp[i][j] =0;
                }else{
                    dp[i][j] =  1e18;
                    for(int k = i;k<j;k++){
                        dp[i][j] = min(dp[i][k] + dp[k+1][j] + presum[j+1] - presum[i],dp[i][j] );
                    }
                }
            }
        }
        LL ans = 1e18;
        for(int i=0;i<n;i++){
            ans = min(ans,dp[i][i+n-1]);
        }
        cout << ans << endl;
    }
    

    return 0;
}