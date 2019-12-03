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



int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
    
   
    int n;
    cin >> n;
    pair<int,int> a[n],b[n];
    forn(i,n){
        cin >> a[i].F  >> a[i].S;
    }
    forn(i,n){
        cin >> b[i].F  >> b[i].S;
    }
    int cost[n][n];
    auto cc = [&](pair<int,int> aa,pair<int,int>bb){
        return (abs(aa.F - bb.F) + abs(aa.S - bb.S));
    };
    forn(i,n){
        forn(j,n){
            cost[i][j] = cc(a[i],b[i]);
        }
    }
    int mask  = (1 << n);
    int dp[mask];
    forn(i,mask)dp[i] =1e9;
    dp[0] = 0;
    forn(i,mask){
        int x = __builtin_popcount(i);
        forn(j ,n){
            if(!(i&(1 << j))){
                dp[i|(1 <<j)] = min(dp[i|(1 <<j)],dp[i]+cost[x][j]);
                //trace(dp[i|(1 <<j)],dp[i]+cost[x][j]);
            }
        }
    }
   // forn(i,mask)cout << dp[i] << endl;
    cout << dp[mask-1] << endl;


#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}