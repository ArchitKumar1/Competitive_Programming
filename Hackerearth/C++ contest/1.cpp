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

const int N = 5e5 + 100;

int arr[N];
int dp[N][12];
vector<int> primes{2,3,5,7};#include<bits/stdc++.h>
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

const int N = 5e5 + 100;

int arr[N];
int dp[N][12];
vector<int> primes{2,3,5,7};
void help(int i ,int x){
    for(int j : primes){
        int y = x;
        int ans = 0;
        while(y%j == 0){
            ans++;
            y = y/j;
        }
        dp[i][j] = ans;
    }
}
            
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    int n,m;
    cin >> n >> m;

    forn(i,n) cin >> arr[i+1];

    for(int i=1;i<=n;i++){
        help(i,arr[i]);
        
        for(int j=0;j<12;j++){
            dp[i][j] += dp[i-1][j];
        }
        
    }
    // for(int i=1;i<=n;i++){
    //     for(int j = 0;j<12;j++){
    //         trace(i,j,dp[i][j]);
    //     }
    //     cout << endl;
    // }
    while(m--){
        int l,r;
        cin >> l >> r;
        int ans = 1;
        for(int i=2;i<12;i++){
            int temp = dp[r][i] - dp[l-1][i];
            //trace(dp[r][i],dp[l-1][i]);
            ans*= (temp+1);
            ans%= mod;
            //trace(ans);
        }
        cout << ans << endl;
    }
    return 0;
}
void help(int i ,int x){
    for(int j : primes){
        int y = x;
        int ans = 0;
        while(y%j == 0){
            ans++;
            y = y/j;
        }
        dp[i][j] = ans;
    }
}
            
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    int n,m;
    cin >> n >> m;

    forn(i,n) cin >> arr[i+1];

    for(int i=1;i<=n;i++){
        help(i,arr[i]);
        
        for(int j=0;j<12;j++){
            dp[i][j] += dp[i-1][j];
        }
        
    }
    // for(int i=1;i<=n;i++){
    //     for(int j = 0;j<12;j++){
    //         trace(i,j,dp[i][j]);
    //     }
    //     cout << endl;
    // }
    while(m--){
        int l,r;
        cin >> l >> r;
        int ans = 1;
        for(int i=2;i<12;i++){
            int temp = dp[r][i] - dp[l-1][i];
            //trace(dp[r][i],dp[l-1][i]);
            ans*= (temp+1);
            ans%= mod;
            //trace(ans);
        }
        cout << ans << endl;
    }
    return 0;
}