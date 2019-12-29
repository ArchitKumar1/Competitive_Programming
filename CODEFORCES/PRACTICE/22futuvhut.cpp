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

string bin(int n){
    string ans ="";
    while(n){
        if(n%2 ==0 ){
            ans += "0";
        }else{
            ans += "1";
        }
        n >>=1;
    }
    reverse(ALL(ans));
    return ans;
}
LL mul(LL a,LL b){
    LL ans = (a*b)%mod;
    return ans;
}
LL add(LL a,LL b){
    return (a+b)%mod;
}
LL pow(LL a,LL b,LL mod){
    LL res = 1;
    while(b){
        if(b&1) res = (res*a)%mod;
        a = ((LL)a*a)%mod;
        b>>=1;
    }
    return res;
}
int maxpow2(int n){
    int ans =0 ;
    while(n){
        ans += 1;
        n>>=1;
    }
    return ans;
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
    
    TC{
        int l,r;
        cin >> l >> r;
        l--;
        LL ra = 0;
        LL la = 0;
        for(int i =0;i<=31;i++){
            int divisor = pow(2,i);
            if(i == 0) ra += r/divisor;

            else ra += (LL)pow(2,i-1)*(r/divisor) ;

             if(i == 0) la += l/divisor;

            else la += (LL)pow(2,i-1)*(l/divisor) ;
            trace(ra,la,i);
            
        }

        cout << ra - la << endl;
    }

#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}