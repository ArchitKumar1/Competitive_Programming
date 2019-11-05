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

vector<vector<int>> G;
vector<int> in,out;
int fans = 0;

void dfs1(int s,int par){
    for(int c : G[s]){
        if(c == par ) continue;
        dfs1(c,s);
        in[s] = max(in[s],1 +in[c]);
    }
}

void dfs2(int s,int par){
    int c1=-1,c2=-1;
    for(int c : G[s]){
        if(c == par) continue;
        trace(s+1,c+1,in[c]);
        if(in[c] >=c1){
            swap(c1,c2);
            c1= in[c];
        }else if(in[c] >=c2){
            c2 = in[c];
        }
    }
    trace(s+1,c1,c2);
    for(int c: G[s]){
        int longest = c1;
        if(c == par) continue;
        if(in[c] == c1) longest = c2;
        out[c] = max(2+in[longest],1+out[s]);
        trace(out[s],s+1);
        dfs2(c,s);
    }
    
}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    int n,m;
    cin >> n;
    G.resize(n);
    in.assign(n,0);
    out.assign(n,0);
    forn(i,n-1){
        int x,y;
        cin >> x>> y;
        --x;--y;
        G[x].PB(y);
        G[y].PB(x);        
    }
    dfs1(0,-1);
    dfs2(0,-1);
    int maxval =0 ;
    int maxnode = -1;

    for(int i=0;i<n;i++){
        if(max(in[i],out[i])> maxval){
            maxval = max(in[i],out[i]);
            maxnode = i;
        }
    }

    cout << maxnode << " " << maxval << endl;
    for(int i=0;i<n;i++){
        trace(i,in[i],out[i]);
    }
    for(int i=0;i<n;i++){
        cout << in[i] << " ";
    }

}




