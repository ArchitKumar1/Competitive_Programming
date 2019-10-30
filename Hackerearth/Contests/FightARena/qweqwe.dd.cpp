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
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


////////////////////////////

const LL N  = 1234567;

LL fact[N];
const LL m = 1e6 + 3;
LL modc(LL a,LL b,LL c){
    LL res=  1;
    while(b){
        if(b&1) res = ((LL)a*res)%m;
        a = ((LL)a*a)%m;
        b>>=1;
    }
    return res;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    fact[0] = 1;
    for(LL i=1;i<N;i++){
        fact[i] = ((LL)i*fact[i-1])%m;
    }
    TC{
        LL n,x;
        cin >> n >> x;
        LL q = n/m;
        LL fans = 1;
        LL rem = n%m;
        fans = modc(fact[m],q,m)%m ;
        fans = (x*fans*(fact[rem])%m)%m;
        cout << fans <<endl;
    }
    
    
}




