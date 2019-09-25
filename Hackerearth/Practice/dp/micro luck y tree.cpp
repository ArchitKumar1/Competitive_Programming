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
 

int main(){
 
FASTIO    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    int t;
    cin >> t;
    while(t--){
        LL a,b,c;
        cin >> a >> b >> c;
        a--;
        c--;
        LL  gans = 0;
        for(LL  B = 1;B<=b;B++){
            LL  fans = 0;
            for(int i = 1;i<=min(max(a,c),B);i++){
                double temp = 1.0 * B * B / i;
                temp = floor(temp);
                if(i<=min(a,B)){
                    int temp1 = min((LL )temp,c);
                    fans += temp1;
                }
                if(i<=min(c,B)){
                    int temp2 = min((LL )temp,a);
                    temp2 = max((LL )temp2-B,0LL);
                    fans += temp2;
                }
            }
            gans += (a*c)%mod - (fans)%mod + mod;
            gans %= mod;
        }
        cout << gans << endl;
        
    }
    

    return 0;
}