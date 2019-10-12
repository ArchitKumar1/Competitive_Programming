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

int solve(int n,int x){

    if(x == 1){
        if(n == 0) return dp1[n] = a[n];
        if(dp1[n] != 1e9) return dp1[n]; 
        int t1 = a[n] + solve(n-1,1);
        int t2 = a[n] + cb[n-1] + solve(n-1,0);
        return dp1[n]=  min(t1,t2);
    }else{
        if(n == 0 ) return dp2[n] = b[n];
        if(dp2[n] != 1e9) return dp2[n]; 
        int t1 = b[n] + solve(n-1,0);
        int t2 = b[n] + ca[n-1] + solve(n-1,1);
        return dp2[n] = min(t1,t2);
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    TC{
        int n;
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
        cout << min(solve(n-1,0),solve(n-1,1)) << endl;
    }
    return 0;
}




