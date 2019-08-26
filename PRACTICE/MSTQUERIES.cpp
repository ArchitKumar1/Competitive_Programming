#include<bits/stdc++.h>
#pragma GCC optimize("O3","Ofast")
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){return os<<"("<<P.first<<","<<P.second<<")";}
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


map<pair<int,int>,int> m1,m2;
vector<pair<pair<int,int>,int>> mst;
const int N = 12345;
int par[N],size[N];
int n,m,q;
int find(int v){
    if(par[v] == v){
        return v;
    }else return par[v] = find(par[v]);
}
int fans = 0;
void merge(int a,int b){
    if(find(a)!= find(b)){
        a = find(a);
        b = find(b);
        if(size[a] < size[b]) swap(a,b);
        par[b] =a ;
        size[a]+= size[b];
    }
}
void solve(){
    for(int i=0;i<n;i++){
        par[i] = i;
        size[i] = 1;
    }
    vector<pair<int,pair<int,int>>> all;
    for(auto x : m2){
        //cout << x.S << " " << x.F.F << " " << x.F.S << endl;
        all.PB({x.S,{x.F.F,x.F.S}});
    }
    sort(all.begin(),all.end());
    fans = 0;
    int pos =0 ;
    for(auto x: all){
        //cout << x.F << " " << x.S.F << " " << x.S.S << endl;
    }
    int req = 0;
    while(req!=n-1){
        pair<int,pair<int,int>> temp = all[pos++];
        int a =find(temp.S.F);
        int b =find(temp.S.S);
        if(a!= b){
            merge(a,b);
            fans += temp.F;
            req++;
        }
    }
    
        
}
int main(){
    cin >> n >> m >> q;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin >>u >> v >> w;
        u--;v--;
        m1[{u,v}] = w;
        m1[{v,u}]= w;
        m2[{u,v}] = w;
        m2[{v,u}]= w;
    }
    solve();
    for(int i=0;i<q;i++){
        int x;
        cin >> x;
        int y,z;
        if(x == 1){
            
            cin >> y >> z;
            y--;z--;
            m2[{y,z}] = 0;
            m2[{z,y}] = 0;
            solve();
        }
        else if(x == 2){
            cin >> y >> z;
            y--;z--;
            m2[{y,z}] = m1[{y,z}];
            m2[{z,y}] = m1[{z,y}];
            solve();
        }else{
            cout << fans <<  endl;
        } 
    }
}