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

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////
vector<vector<pair<int,double>>> G;
int n;
int m;
double fans = 0;

bool dij(int st,int en){
    vector<double> dist(n,1e18);
    vector<int> vis(n,0);
    dist[st] =0;
    set<pair<double,int>> all;
    all.insert({0,st});
    while(all.size()){
        pair<int,int> temp = *all.begin();
        all.erase(*all.begin());
        if(vis[temp.S]) continue;
        vis[temp.S] = 1;
        for(auto c : G[temp.S]){
            if(dist[c.first] > dist[temp.S] + c.second){
                dist[c.first] = dist[temp.S] + c.second;
                all.insert({dist[c.first],c.first});
            }
        }
    }

    if(dist[en]!=1e18){
        fans = dist[en];
        return 1;
    }else{
        return 0;
    }
}
int main(){
    cout << setprecision(10) << fixed;
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
   

    TC{
        cin >> n;
        G.assign(n,vector<pair<int,double>>());
        cin >> m;
        int st,en;
        cin >> st >> en;
        st--;en--;
        forn(i,m){
            int x,y,l,s;
            cin >>x >> y >> l >> s;
            x--;y--;
            
            double z =1.0 * l/s;
            G[x].PB({y,z});
            G[y].PB({x,z});
        }
        if(dij(st,en)){
            cout << fans << endl;
        }else{
            cout << "-1" << endl;
        }
    }
    
}




