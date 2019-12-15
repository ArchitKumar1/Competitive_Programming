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

const int N = 123456;
vector<pair<int,string>> G[N];
int cnt[N][26];

const int L = 25;
int timer = 0;
vector<int> tin(N), tout(N);
int up[N][L+1] ={0};

void dfs1(int s,int par){
    tin[s] = ++timer;
    up[s][0] = par;
    for (int i = 1; i <= L; ++i)
        up[s][i] = up[up[s][i-1]][i-1];
    for(pair<int,string> c : G[s]){
        if(par == c.F) continue;
        dfs1(c.F,s);
    }
    tout[s] = ++timer;
}
bool is_ancestor(int u, int v){
    return tin[u] <= tin[v] && tout[u] >= tout[v];
}

int lca(int u, int v){
    if (is_ancestor(u, v)) return u;
    if (is_ancestor(v, u))  return v;
    for (int i = L; i >= 0; --i) {
        if (!is_ancestor(up[u][i], v))
            u = up[u][i];
    }
    return up[u][0];
}
void dfs2(int s,int par,string pass = ""){
  //  trace(pass);
    for(char c : pass){
        cnt[s][c-'a']+=1;
    }
    if(par!=-1){
        for(int i=0;i<26;i++){
            cnt[s][i] += cnt[par][i];
        }
    }
    for(pair<int,string> c : G[s]){
        if(par == c.F) continue;
        dfs2(c.F,s,c.S);
    }
}
int main(){
    FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
    int n;
    cin >> n;
    forn(i,n-1){
        int x,y;
        cin >> x >> y;
        --x;--y;
        string s;
        cin >> s;
        G[x].EB(y,s);
        G[y].EB(x,s);
    }
    dfs1(0,-1);
    dfs2(0,-1);
    
    int q;
    cin >> q;
    while(q--){
        int x,y;
        cin >> x>> y;
        --x;--y;
        int LCA = lca(x,y);
        vector<int> chars(26,0);
        int total =0;
        for(int i=0;i<26;i++){
            chars[i] = cnt[x][i] + cnt[y][i] - 2*cnt[LCA][i];
            total += chars[i];
        }
       // cout << chars;
        int odd=0;
        for(int i=0;i<26;i++){
            if(chars[i]%2 == 1){
                odd++;
            }
        } 
        if(odd<=1){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
        
    }
   

}