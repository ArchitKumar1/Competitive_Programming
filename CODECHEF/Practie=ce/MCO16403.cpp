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


const int N = 3e5 + 4;
vector<int> G[N];

vector<int> total(N), below(N), top(N),all(N),up(N);
void dfs(int s,int par){
    total[s] = 1;
    below[s] = 0;
    for(int c : G[s]){
        if(c == par )
            continue;
        dfs(c, s);
        total[s] += total[c];
        below[s] += below[c] + total[c];
    }

}

void dfs2(int s,int par){
    int val1 =  0;
    int val2 = 0;
    val1 = up[par] + below[par] - below[s] - total[s] ;
    val2 = below[par] - below[s] - total[s] + total[par] - total[s]
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for (int i = 0; i < n - 1;i++){
        int x, y;
        cin >> x >> y;
        G[x].PB(y);
        G[y].PB(x);
    }
    dfs(0, -1);
    for (int i = 0; i < n;i++){
        cout << below[i] << " ";
    }
    
    return 0;
}