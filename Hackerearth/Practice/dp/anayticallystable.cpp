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

const int mod = 1000*1000*1000 + 7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////


int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    TC{
        
        string s;
        cin >> s;
        int n = s.length();
        int dp1[n][12],dp2[n][12];
        memset(dp1,0,sizeof(dp1));
        memset(dp2,0,sizeof(dp2));

        for(int i=0;i<n;i++){
            dp1[i][s[i]-'0'] =1;
            dp2[i][s[i]-'0'] =1;
        }
        for(int i =1;i<n;i++){
            forn(j,10){
                dp1[i][j] += dp1[i-1][j];
                
            }
        }
        for(int i =n-2;i>=0;i--){
            forn(j,10){
                dp2[i][j] += dp2[i+1][j];
            }
        }
        LL fans = 0;
        for(int i =1;i<n-1;i++){
            LL c = s[i] - '0';
            LL l,r;
            l = dp1[i-1][c];
            r = dp2[i+1][c+1];
            //trace(c,l,r);
            r = r*(r-1)/2;
            r%= mod;
            fans+= (l*r)%mod;
            fans%= mod;
        }

        cout << fans << endl;
    }
    return 0;
}




