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
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


////////////////////////////
struct edge{
    int x,y,z;
    bool operator<(const edge &e){
        return z < e.z;
    }
};
vector<int> par,size;

void make(int n){
    forn(i,n){
        par[i] = i;
        size[i] = 1;
    }
}
int find(int v){
    if(par[v] == v)return v;
    else return par[v] =find(par[v]);
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(size[a] < size[b])swap(a,b);
        par[b] = a;
        size[a] += size[b];
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    TC{
        int n,m;
        cin >> n >> m;
        par.assign(n,0);
        size.assign(n,0);
        vector<edge>all;
        make(n);
        forn(i,m){
            int x,y,z;
            cin >> x >> y >> z;
            --x,--y;
            all.PB({x,y,z});
            all.PB({y,x,z});
        }
        sort(ALL(all));
        // for(edge e : all){
        //     cout << e.x << " " << e.y << " " << e.z << endl;
        // }
        int pos = 0;
        LL fans = 1;
        for(edge e : all){
            //trace(find(e.x),find(e.y));
            if(find (e.x)!=find(e.y)){
                //trace(fans);
                fans *= e.z;
                fans%= mod;
                merge(e.x,e.y);
            }
        }
        cout << fans << endl;
    }
    
    
    
}




