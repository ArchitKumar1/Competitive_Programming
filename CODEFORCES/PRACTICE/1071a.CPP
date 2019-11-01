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

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    LL a,b;
    cin >> a >> b;
    LL sum = a+b;
    LL l = 0;
    LL h = pow(1LL<<32,0.5);
    LL ub = h;
    LL ans = 0;

    while(l<=h){
        LL m  =(l+h)>>1;
        if((LL)(m*(m+1)) <= 2*sum){
            ans = m;
            l = m+1;
        }else{
            h = m-1;
        }
    }
    map<LL,LL> m1,m2;
    //trace(ans);
   LL ansa = 0,ansb= 0;
    for(LL i=ans;i>=1;i--){
        if(a - i>=0){
            ++ansa;
            //trace(a,i);
            a-=i;
            m1[i]=1;
            //trace(i,a);
        }
    }
    for(LL i=1;i<=ans;i++){
        
        if(m1[i]!=1){
            ++ansb;
           // trace(i);
            m2[i] =1;
        }   
    }
    cout << ansa << endl;
    for(auto x: m1){
        if(x.S == 1)cout << x.F << " ";
    }
    cout << endl;

    cout << ansb << endl;
    for(auto x: m2){
        if(x.S == 1)cout << x.F << " ";
    }
    cout << endl;
    
    
    
    
}




