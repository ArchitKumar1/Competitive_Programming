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

const int N = 1e5 + 5;
vector<int> G[N];
vector<int> mini(N, INT_MAX), maxi(N, INT_MIN),val(N,0);
int ans = 0;

void dfs(int s){
    int a = val[s];
    int b = val[s];
    int children = 0;
    for(int c : G[s]){
        dfs(c);
        a = min(a, mini[c]);
        b = max(b, maxi[c]);
    }
    
    mini[s] = a;
    maxi[s] = b;
    ans = max(ans, max(abs(mini[s] - val[s]), abs(maxi[s] - val[s])));
    
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0;i<n;i++){
        cin >> val[i];
    }
    int root;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        if(x == -1)
            root = i;
        else{
            G[--x].PB(i);
        }
    }
    dfs(root);
        cout << ans << endl;
    return 0;
}