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


LL pow(LL a, LL b,LL c){
    LL res = 1;
    a = a%c;
    while(b){

        if(b&1) res = (res*a)%c;
        a =(a*a)%c; 
        b >>=1;
    }
    return res;
}

const LL N = 1234;

LL fact[N],inv[N];

int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    

    for(LL i= 0;i<N;i++){
        if(i == 0) fact[i] = 1;
        else fact[i] = (i*fact[i-1])%mod;
        inv[i] =  pow(fact[i],mod-2,mod)%mod;
    }

    TC{
        LL n,p;
        cin >> n >> p;
        LL res = 1;
        for(LL i =1;i<=p;i++){
            //trace((fact[n] * (inv[n-i] * inv[i])%mod)%mod);
            LL temp = inv[n-i] * inv[i];
            temp%= mod;
            res += (fact[n] * temp)%mod;
            res%=mod;
           // res += ((LL)fact[n] * (inv[n-i] * inv[i])%mod)%mod;
        }
        cout << res << endl;
    }

}