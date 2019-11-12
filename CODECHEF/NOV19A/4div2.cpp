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


struct circle{
    double x,y,r;
};
struct point {
    double x,y;
};
bool inside(const point &p,const circle &c){    
    double dist = (p.x-c.x)*(p.x-c.x) + (p.y-c.y)*(p.y-c.y) -c.r;
    return (dist<=0);
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
     
    int q;
    cin >> q;
    vector<circle>allc;
    int insofar = 0;
    int prev= 0;
    while(q--){
        int x;
        cin >> x;
        if(x == 1){
            circle c;
            cin >> c.x >> c.y >> c.r;
            //c.r = sqrt(c.r);
            allc.push_back(c);
        }else{
            point p;
            cin >> p.x >> p.y;
            if(insofar>=1 && prev>=1) swap(p.x,p.y);
            bool ok = 1;
            for(circle c : allc){
                ok&= inside(p,c);
            }
            if(ok) {
                insofar++;
                prev= 1;
            }else{
                prev = 0;
            }
            if(ok){
                cout << "1" << endl;
            }else{
                cout << "0" << endl;
            }
        }
    }
}