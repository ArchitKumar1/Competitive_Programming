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
 int n,m;
vector<vector<pair<int,int>>> G;
vector<int> dist;
void dij(int s){
    dist.assign(n,inf);
    dist[s] = 0;
    set<pair<int,int>> ss;
    ss.insert({0,s});
    while(ss.size()){
        pair<int,int> temp = *ss.begin();ss.erase(ss.begin());
        for(pair<int,int> c : G[temp.S]){
            if(dist[c.F] > dist[temp.S] +  c.S){
                ss.insert({dist[c.F] = dist[temp.S] + c.S,c.F});
            }
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    cin >> n >> m;
    G.assign(n,vector<pair<int,int>>());
    forn(i,m){
        int x,y,z; cin >> x>> y >> z; --x;--y;
        G[x].PB({y,z}) ; G[y].PB({x,z});
    }
    dij(0);
    trace(dist);
    return 0;
}




