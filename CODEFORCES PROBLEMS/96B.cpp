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
    
    vector<string> all;
    queue<string> qq;

    qq.push({""});

    int limit = 10;
    while(qq.size()){
        string s = qq.front();
        if(s!=""){
            int c = 0;
            for(char cc : s){
                c += cc == '4';
                c -= cc == '7';
            }
            if(c == 0){
                all.PB(s);
            }
        }
        qq.pop();
        if(s.size()<limit){
            qq.push(s + '4');
            qq.push(s + '7');
        }
    }
    vector<LL> all2;
    for(string x : all){
        all2.PB(stoll(x));
    }
    sort(ALL(all2));
    int n;
    cin >> n;

    int l = 0;
    int h = all2.size()-1;

    int fans = 0;
    while(l<=h){
        int mid = (l+h) >> 1;
        if(all2[mid] >= n){
            fans = mid;
            h = mid-1;
        }else{
            l = mid + 1;
        }
    }
    cout << all2[fans] << endl;
    return 0;
}