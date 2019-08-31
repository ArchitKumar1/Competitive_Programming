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

#define DEBUG1(x) cout  << '>' << " " << #x << ':' << " " <<  x << endl;
#define DEBUG2(x,y) cout  << '>' << " " << #x << ':' << " " <<  x <<  " " << #y << ':' << " " <<  y <<endl;
#define DEBUG3(x,y,z) cout  << '>' << " " << #x << ':' << " " <<  x << " " << #y << ':' << " " <<  y <<" " << #z << ':' << " " <<  z << " " <<endl;
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

const int mod = 10*9+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


const int N = 1233;
int fans = INT_MIN;
vector<int> G[N];
pair<int,int> max2[N];
vector<int> in(N),out(N);

void dfs(int s,int par){
    int mx = 0;
    vector<int> all;
    for(int c : G[s]){
        if(c!=par){
            dfs(c,s);
            mx = max(mx,1 + in[c]);
            all.PB(in[c]);
        }
    }
    sort(ALL(all));
    reverse(ALL(all));
    if(all.size() >= 1) max2[s].F  = all[0];
    if(all.size() >= 2) max2[s].S  = all[1];
    in[s]  = 0 + mx;
}

void dfs2(int s,int par){
    
    if(s == 1) {
        out[s] = in[s];
        fans = max(fans,max2[s].F + max2[s].S);
    }
    else{
        out[s] = max(1 + out[par],1 + max2[par].S);
        fans = max(fans,in[s] + out[s]);  
    }
    DEBUG3(s,in[s],out[s]);
    for (int c :G[s]){
        if(c!=par)
        dfs2(c,s);
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
        G[x].PB(y);
        G[y].PB(x);
    }
    dfs(1,0);
    dfs2(1,0);
    cout << fans << endl;
    
}