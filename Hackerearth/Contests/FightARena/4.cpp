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

/////////////////////////////

const LL N = 123456;
vector<pair<LL, LL>> size(N);
VI par(N, 0);
void make(LL v,LL type){
    if(type == 1){
        size[v].F = 1;
        size[v].S = 0;
    }else{
        size[v].F = 0;
        size[v].S = 1;
    }
    par[v] = v;
}
LL find(LL v){
    return par[v] == v ? v : par[v] = find(par[v]);
}
void merge(LL a,LL b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(size[a].F + size[a].S < size[b].F + size[b].S ){
            swap(a, b);
        }
        par[b] = a;
        size[a].F += size[b].F;
        size[a].S += size[b].S;
    }
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

     LL c,d;
     cin >> c >> d;
     for (LL i = 0; i < c;i++){
         make(i, 1);
     }
     for (LL i = c; i < c + d;i++){
         make(i, 0);
     }

    LL q1;
     cin >> q1;
     forn(i, q1)
     {
         LL x, y;
         cin >> x >> y;
         --x;--y;
         merge(x, y);
    }
    LL q2;
     cin >> q2;
    forn(i,q2){
        LL x, y;
         cin >> x >> y;
         --x;--y;
         merge(x+c, y+c);
    }
    LL q3;
     cin >> q3;
    forn(i,q3){
        LL x, y;
         cin >> x >> y;
         --x;--y;
         merge(x , y+c);
    }
    map<LL, LL> m2;
    vector<LL> res;
    for (LL i=0;i<c;i++){
        LL p = find(i);
        if(!m2[p]){
            m2[p] = 1;
            res.PB(p);
        }
    }
    for (LL i=c;i<c + d;i++){
        LL p = find(i);
        if(!m2[p]){
            m2[p] = 1;
            res.PB(p);
        }
    }
    VI male, female;
    for(LL c : res){
        LL a = size[c].F;
        male.PB(a);
        LL b = size[c].S;
        female.PB(b);
    }
    LL msum = 0, fsum = 0;
    for (LL c : male){
        msum += c;
    }
    for (LL c : female){
        fsum += c;
    }
    LL ans = 0;
    for (LL i = 0; i < res.size();i++){
        ans += male[i] * (fsum - female[i]);
    }
    cout << ans << endl;

#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
}