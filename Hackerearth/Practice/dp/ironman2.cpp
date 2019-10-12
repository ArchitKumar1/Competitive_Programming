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
vector<int> a,b,ca,cb,dp1,dp2;
int n;
int solve(){
    forn(i,n){
        if(i == 0){
            dp1[i] = a[i];
            dp2[i] = b[i];
        }
        dp1[i] = min(dp1[i],dp1[i-1] + a[i]);
        dp1[i] = min(dp1[i],dp2[i-1] + cb[i-1]+ a[i]);

        dp2[i] = min(dp2[i],dp2[i-1] + b[i]);
        dp2[i] = min(dp2[i],dp1[i-1] + ca[i-1]+ b[i]);
    }
    return min(dp1[n-1],dp2[n-1]);
}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    TC{
        
        cin >> n;
        a.assign(n,0);
        b.assign(n,0);
        ca.assign(n,0);
        cb.assign(n,0);
        dp1.assign(n,1e9);
        dp2.assign(n,1e9);
        forn(i,n) cin >> a[i];
        forn(i,n) cin >> b[i];
        forn(i,n-1) cin >> ca[i];
        forn(i,n-1) cin >> cb[i]; 
        //trace(solve(n-1,0),solve(n-1,1));
        cout << solve() << endl;
    }
    return 0;
}




