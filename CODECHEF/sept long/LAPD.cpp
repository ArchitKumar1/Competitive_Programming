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
 
const int mod = pow(10,9) +9;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;
 
 
/////////////////////////////
 
 
int main(){
 
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    int a,b,c;
    cin >>  a >> b >> c;
    a--;
    c--;
    // int fans = 0;
    // for(int k = 1;k<= b;k++){
    //     for(int i=1;i<=a;i++){
    //         for(int j = 1;j<=c;j++ ){
    //             double ans = pow(1.0*i*j,0.5);
    //             if(ans > (double)k){
    //                 trace(k,i,j,ans);
    //                 fans++;
    //             }
    //         }
    //     }
    // }
    
    // cout << fans << endl;
    LL tans = 0;
    if(a < c) swap(a,c);
    int doofus[b+1];
    
    for(int k = 1;k<=b;k++){
        for(int i = 1;i<=min((int)pow(c,0.5),b);i++){
            int rev = b / c;
            trace(k,a,c,rev,min(a,rev));
            tans += min(a,rev);
        }
        
    }
    trace(a*b*c,2*tans);
    cout << a*b*c - 2 *tans << endl;
    return 0;
}