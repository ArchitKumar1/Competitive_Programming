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


const int N = 3.1e3;
int par[N],size[N];
void make(int n){
    forn(i,n){
        par[i]  =i;
        size[i] = i;
    }
}
int find(int v){
    if(par[v] == v) return v;
    else return par[v] = find(par[v]);
}
void merge(int a,int b){
    a = find(a);b =find(b);
    if(a!=b){
        if(size[a] < size[b]) swap(a,b);
        par[b] =a ;
        size[a] += size[b];
    }
}

struct edge{
    int u,v;
    LL w;
    bool operator<(const edge &b ){
        return w > b.w;
    }
};
LL dist(pair<LL,LL> a,pair<LL,LL> b){
    LL ans = (a.F-b.F)*(a.F-b.F) + (a.S-b.S)*(a.S-b.S);
    return ans;
}
vector<edge> all;
vector<pair<LL,LL>> G(N);
int grid[N][N];

int main(){   
    FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
    
        int n;
        cin >> n;
        forn(i,n){
            cin >> G[i].F >> G[i].S;
            G[i].F--;G[i].S--;
        }
        forn(i,n)forn(j,n){
            cin >> grid[i][j];
        }
        forn(i,n)forn(j,n){
            if(i==j) continue;
            if(grid[i][j]==0) continue;
            all.PB({i,j,dist(G[i],G[j])});
        }
        sort(all.begin(),all.end());
        make(n);

        LL fans= 0;
        make(n);
        for(edge p : all){
            if(find(p.u)!=find(p.v)){
                merge(p.u,p.v);
                fans += p.w;
            }
        }
        set<int> s;
        for(int i=0;i<n;i++){
            s.insert(find(i));
        }
        if(s.size()==1){
            cout <<fans << endl;
        }else{
            cout << "-1" << endl;
        }

}