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
const int N = 1234;

vector<vector<pair<int,int>>> G(N);


void dij(int st,int de,int t){
    
    vector<int> dist(N,0);
    vector<int> vis(N,0);
    vector<int> order(N,0);
    priority_queue<pair<int,pair<int,int>>> pq;
    pq.push({1e8,{st,-1}});
    while(pq.size()){
        pair<int,pair<int,int>> temp =pq.top();pq.pop();
        if(vis[temp.S.F] == 1)continue;
        vis[temp.S.F] =1;
        
        if(temp.F >dist[temp.S.F]){
            dist[temp.S.F] = temp.F;
           if(temp.S.F!=-1) order[temp.S.F] = temp.S.S;
        }
        if(temp.S.F == de) continue;
        for(pair<int,int> p :G[temp.S.F]){
            pq.push({min(p.S,temp.F),{p.F,temp.S.F}});
        }
    }
    vector<int> path;
    for(int i=de;i!=0;i= order[i]){
        path.PB(i);
    }
    path.PB(st);
    reverse(ALL(path));
    for(int i=0;i<path.size();i++){
        cout << path[i]+1 ;
        if(i!=path.size()-1)cout << " ";
    }cout << endl;
    int number = dist[de]-1;
    cout <<  (t/number + ((t%number)>=1));
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
    int n,m;
    cin >> n >> m;
    forn(i,m){
        int x,y,z;
        cin >> x>> y >> z;
        --x;--y;
        G[x].EB(y,z);
        G[y].EB(x,z);
    }
    int st,de,t;
    cin >> st >> de >> t;
    --st;--de;--t;
    dij(st,de,t);
   #ifndef ONLINE_JUDGE
        cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif

}