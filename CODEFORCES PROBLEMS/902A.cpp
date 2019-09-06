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

vector<pair<int,int>> all;

const int N = 123;
int par[N],size[N];

void make(int v){
    par[v] = v;
    size[v] = 1;
}
int find(int v){
    if(v == par[v]) return v;
    else return par[v]= find(par[v]);
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(size[a] > size[b]) swap(a,b);
        par[b] = a;
        size[a] += size[b];
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<pair<int,int>> all(n);
    for(int i=0;i<n;i++){
        cin >> all[i].F >> all[i].S;
    }
    sort(ALL(all));
    vector<int> vis(m + 1,0);
    vis[0] = 1;
    bool ok = 1;
    for(auto p : all){
        int l = p.first;
        int r = p.second;
        if(vis[l] == 1){
            for(int i=l+1;i<=r;i++){
                vis[i] = 1;
            }
        }else{
            ok = 0;
            break;
        }
    }
    // for(int i=0;i<=m;i++){
    //     cout << vis[i] << " ";
    // }
    if(n == 1 && m == 1 && all[0].F == 0 && all[0].S == 0) cout << "NO" << endl;
    else cout << (vis[m]  ? "YES" :"NO" ) << endl;
    return 0;
}