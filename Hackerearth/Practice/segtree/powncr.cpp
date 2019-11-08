#include<bits/stdc++.h>
#pragma optimize("O3","-ofast")
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


const int N  = 1e6+100;

LL fact[N];
LL invfact[N];

LL powe(LL a,LL b,LL c){
    a = a%c;
    LL res = 1;
    while(b){
      
        if(b&1) res = (res*a)%c;
        b>>=1;
        a = (a*a)%c;
        
    }
    return res;
}


int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
   
    fact[0] =1,invfact[0] =1,invfact[1] =1;
    for(int i=1;i<N;i++){
        fact[i] = (i*fact[i-1])%mod;
    }
    for(int i=1;i<N;i++){
        invfact[i] = powe(fact[i],mod-2,mod);
    }

    int q;
    cin >> q;
    while(q--){
        int n,r;
        cin >> n >> r;
        cout << ((fact[n] * invfact[n-r])%mod * invfact[r])%mod << endl;
    }

}