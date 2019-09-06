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

struct edge{
    int a,b,c;
    bool operator<(const edge &x) {
        return x.c > c;
    }
};

const int N = 324567;
vector<edge> all;
vector<int> size(N,0),par(N);
vector<LL> qans (N,0);
vector<pair<int,int>> queries;

void make(int v){
    par[v] = v;
    size[v] = 1;
}
int find(int v){
    if(par[v] == v){
        return v;
    }else{
        return par[v] = find(par[v]);
    }
}
LL fans = 0;
void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a == b) return;
    if(size[a] < size[b]){
        swap(a,b);
    }
    par[b] = a;
    //trace(a,b,size[a],size[b]);
    fans += (LL)size[a] * size[b];
    size[a] += size[b];
    
}
int main(){
FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n,q;
    cin >> n >> q;
    if(n == 1){
        forn(i,q){
            cout << "0 ";
        }
        return 0;
    }
    forn(i,n-1){
        int a,b,c;
        cin >> a >> b >> c;
        a--;b--;
        all.PB({a,b,c});
    }
    for(int i=0;i<n;i++){
        make(i);
    }
    sort(ALL(all));
    forn(i,q){
        int x;
        cin >> x;

        queries.PB({x,i});
    }
    
    
    sort(ALL(queries));
    //trace(queries);
    int pos= 0;
    for(PII p : queries){
        int Q = p.first;
        int id = p.second;
        //trace(pos,all[pos].a,all[pos].b,all[pos].c,Q,id);
        while( all[pos].c <=Q && pos < n-1){
            //trace(pos,all[pos].a,all[pos].b,all[pos].c,Q);
            merge(all[pos].a,all[pos].b);
            pos++;
        }
        //trace(fans);
        qans[id] = fans;
     }
    for(int i=0;i<q;i++){
        cout << qans[i] << " ";
    }
    return 0;

    
    
    
}
