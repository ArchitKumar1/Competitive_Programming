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
 
const int mod = 720720;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;
 

/////////////////////////////

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    string s;
    cin >> s;
    string ops = "";
    vector<LL> vals;
    LL n = s.length();
    for ( char c : s){
        if(c == '+' || c == '*'){
            ops += c;
        }else{
            vals.PB(c-'0');
        }
    }
    LL m = vals.size();
    LL minv[m][m];
    LL maxv[m][m];
    forn(i,m){
        forn(j,m){
            if(i != j){
                minv[i][j] = INT_MAX;
                maxv[i][j] = INT_MIN;
            }else{
                minv[i][j] = maxv[i][j] = vals[i];
            }
        }
    }
    
    for (LL l = 1;l < m;l++){
        for (LL i = 0; i + l < m;i++){
            LL j = i + l;
            LL b = INT_MAX;
            LL a = INT_MIN;
            for (LL k = i;k <j;k++){
                if(ops[k] == '+'){
                    a = max(a,maxv[i][k] + maxv[k + 1][j]); a%= mod;
                    b = min(b,minv[i][k] + minv[k + 1][j]); b%= mod;
                }else{
                    a = max(a,maxv[i][k] * maxv[k + 1][j]); a%= mod;
                    b = min(b,minv[i][k] * minv[k + 1][j]); b%= mod;
                }
            }
            maxv[i][j] = a;
            minv[i][j] = b;
        }
    }
    cout << maxv[0][m - 1] << " " << minv[0][m - 1] << endl;

    return 0;
}