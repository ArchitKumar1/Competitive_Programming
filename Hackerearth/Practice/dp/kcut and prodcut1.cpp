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

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////
const int N = 123456;
vector<int> a(N);
int K;
int n;
int prod(int i,int j){
    int pro = 1;
    for(int x = i;x<=j;x++){
        pro *= a[x];
    }
    return pro;
}
//int sum = 0;
int solve(int i,int j,int K,int sum){
    if(K > (j-i)) return 0;
    if(i == j) return a[i];
    if(K == 0){
        return prod(i,j);
    }
    int ans = INT_MIN;
    for(int k = 0;k<K;k++){
        int l = solve(i,i+k,K-1,sum);
        int r = solve(i+k+1,j,K-1,sum);
        
        if(l!=0 && r!=0){
            sum += (l*r);
        }
        
    }
    return sum;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
FASTIO
    cin >> n;
    forn(i,n) cin >> a[i];
    cin >> K;
    int sum = 0;
    cout << solve(0,n-1,K,sum ) << endl;

    return 0;
}
