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

const int N = 234567;
vector<int> w(N);

vector<vector<int>> G(N);


void dfs(int s,int par,int val ){
    w[s] += val;
    for(int c : G[s]){
        if(c == par ) continue;
        dfs(c,s,val);
    }
}

int 
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
FASTIO
    
    int n;
    cin >> n;
    int q;
    cin >> q;
    forn(i,n) cin >> w[i];
    forn(i,n){
        int x,y;
        cin >> x>> y;
        --x;--y;
        G[x].PB(y);
        G[y].PB(x);
    }
    while(q--){
        int t;
        cin >> t;
        int v,x;
        cin >> v >> x;
         v--;
        if(t == 1){
            w[v]+= x;
        }else{
            int 
            dfs(v,-1,x);
        }
    }


#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}