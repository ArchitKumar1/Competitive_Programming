#include<bits/stdc++.h>
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){return os<<"("<<P.first<<","<<P.second<<")";}

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
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VL;
typedef vector<VL> VLL;
typedef pair<LL,LL>PLL;
typedef vector<PLL> VPLL;

int mod = pow(10,9) +7;

template <typename T,typename U>void add_mod(T &a, U b){a = (LL)a+b;a = a%mod;}
template <typename T,typename U>void mul_mod(T &a, U b){a = ((LL)a*b)%mod;}
template <typename T> T add_mod(vector<T> v){LL sum=0; for(T x : v) sum = (sum + x)%mod;return (T)sum;}
template <typename T> T mul_mod(vector<T> v){ LL sum = 0;for(T x : v)sum = (sum * x)%mod;return (T)sum;}


const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

int m ,n;

bool check(VVI &arr){
    map<int,int> m1[n];
    map<int,int> m2[n];
    bool ok = 1;
    forn(i,n)forn(j,n){
        ok&= ((arr[i][j]<=m) && (arr[i][j]>=1));
        m1[i][arr[i][j]] += 1;
        m2[j][arr[i][j]] += 1;  
    }
    
    //cout << x << endl;
    if(!ok) return false;
    forn(i,n){
        forn(j,m){
            ok&= ((m1[i][j+1] >= 1) ||( m2[i][j+1] >= 1));
        }
    }
    if(!ok) return false;
    return true;
    
}
void solve(int pos,VVI arr){
    if(check(arr) == 1){
        trace(arr);
        return;
    }
    if(pos == n*n){
        return ;
    }
    int i = pos/n;
    int j = pos%n;
    for(int k = 1;k<=m;k++){
        arr[i][j] = k;
        solve(pos+1,arr);
    }

}
int main(){
FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    
    cin >> n;
    m = 2*n-1;
    VVI arr(n,VI(n,0));
    
    solve(0,arr);
    trace("HEllo");


}