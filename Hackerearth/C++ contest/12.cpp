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
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
    int m;
    cin >>m;
    int q;
    cin >> q;
    string s;
    cin >> s;
    
    string t = ' '+ s;
    int n = t.length();
    int dp[n+2][2];

    int initmax = 0;
    memset(dp,0,sizeof(dp));

    for(int i=1;i<=n;i++){
        dp[i][0] = dp[i-1][0] + (t[i] == '1');
        initmax  = max(initmax,dp[i][0]);
    }

    for(int i=n;i>=0;i--){
        dp[i][1] = dp[i+1][0] + (t[i] == '1');
    }
    while(q--){
        int x;
        cin >> x;
        if(x == 1){
            cout << initmax << endl;
        }else{
        
            int pos;
            cin >> pos;
            initmax = max(initmax,dp[pos+1][1] +1 +  dp[pos-1][0]);
            t[pos] ='1';
            trace(t);
            int l = pos-1;
            int r = pos+1;
            l = pos-1 - dp[pos-1][0] + 1;
            
            r = pos+1 + dp[pos+1][1] - 1;
            trace(l,pos,r);
            
            int ltemp = 1 + dp[pos+1][1];
            int rtemp = 1 + dp[pos-1][0];
            dp[l][0] += ltemp;
            dp[r][1] += rtemp;

            initmax = max(initmax,dp[r][1]);
            initmax = max(initmax,dp[l][0]);
            for(int i=1;i<=m;i++){
                cout << dp[i][0] << " ";
            }cout << endl;
            for(int i=1;i<=m;i++){
                cout << dp[i][1] << " ";
            }cout << endl;
        }
    }
}