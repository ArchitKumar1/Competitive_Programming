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

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////


vector<vector<int>> G;
vector<int> vis;

int currtotal =0;
void dfs(int s){
    vis[s] =1;
    currtotal++;
    for(int c : G[s]){
        if(vis[c] == 0){
            dfs(c);
        }
    }
  
}


int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    TC{

    
        int n;
        cin >> n;
        int m;
        cin >> m;
        int r,l;
        cin >> l >> r;
        G.assign(n,vector<int>());
        vis.assign(n,0);
        forn(i,m){
            int x,y;
            cin >> x>> y;
            --x;--y;
            G[x].PB(y);G[y].PB(x);
        }
        LL sum =0;
        forn(i,n){
            currtotal =0 ;
            if(vis[i] == 0){
                dfs(i);
            }else{
                continue;
            }
            //trace(currtotal);
            int req = currtotal -1;
            if(l >=r){
                sum += (l + (LL)req*r);
            }else{
                sum += l*(req+1);
            }
        }
        
        cout << sum << endl;
    }
    
    
}




