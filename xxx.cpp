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
 

 vector<pair<int,vector<pair<int,int>>>> all;

void  solve(int w,int h,vector<pair<int,int>> points){
    int fans =  INT_MIN;
    forn(i,w){
        forn(j,h){
            int temp = INT_MAX;
            for(PII p : points){
                temp = min(temp,abs(p.first-i) + abs(p.second -j));
            }
            fans = max(fans,temp);
        }
    }
    all.PB({fans,points});

}
int main(){
 
FASTIO    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    TC{
        int w,h;
        cin >> w >> h;

        int n = 2;
        int total = w*h;
        vector<pair<int,int>> all1;
        for(int i=0;i+1<total;i++ ){
            for(int j = i+1;j<total;j++){
                int x1= i/w;
                int y1 =i%w;
                int x2 =j/w;
                int y2 =j%w;
                all1.PB({x1,y1});
                all1.PB({x2,y2});
                solve(w,h,all1);
                all1.clear();
            }
        }
        sort(ALL(all));
        cout << all[0] << endl;
        all.clear();
    }
    
    return 0;
}