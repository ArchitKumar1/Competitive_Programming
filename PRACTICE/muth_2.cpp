    #include<bits/stdc++.h>
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


const int N = 100;
int par[N],size[N];

void make(int i){
    par[i] = i;
    size[i] = 1;
}

int find(int v){
    if(par[v] == v){
        return v;
    }else{
        return par[v]  = find(par[v]);
    }
}

void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){
        if(size[a] < size[b]) swap(a,b);
        par[b] = a;
        size[a]+= size[b];
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
    for(int i=0;i<n;i++){
        make(i);
    }
    int q;
    cin >> q;
    while(q--){

        int x,y;
        cin >> x >> y;
        merge(x,y);
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        ans = max(ans,size[find(i)]);
    }
    forn(i,n){
        DEBUG3(i,find(i),size[find(i)]);
    }
    cout << ans << endl;
}