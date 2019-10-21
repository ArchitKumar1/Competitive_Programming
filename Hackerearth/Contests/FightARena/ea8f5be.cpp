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




int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    FASTIO

    TC{
        double x1,y1,x2,y2;
        cin >> x1 >> y1 >> x2 >> y2 ;
        double x = min(abs(x1),abs(x2));
        double y = min(abs(x1),abs(x2));
        double euclid = pow(x*x+y*y,0.5);
        
        double r;
        cin >> r;
        //trace(r);
        double dist;
        if(x2 == x1){
            dist = x1;
        }else{
            //cout << "OK";
            double m = 1.0*(y2-y1)/(x2-x1);
            double c = y1 - m*x1;
            dist = 1.0*c*(pow(1+m*m,0.5));
        }
        //trace(dist,r);
        if(r > dist)cout << "REPLANNING" << endl;
        else if(r == dist) cout << "JUST MISSED" << endl;
        else cout << "SAFE" << endl;
        

    }
    
    return 0;
}




