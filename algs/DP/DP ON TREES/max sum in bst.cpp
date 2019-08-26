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


const int N = 1233;

vector<int> G[N];
vector<int> dp(N,0);
vector<int> vals(N);
int fans = INT_MIN;

void dfs(int s,int par){
    vector<int> allpaths;
    for(int c : G[s]){
        if(c!= par){
            dfs(c,s);
            allpaths.PB(dp[c]);
        }
    }
    sort(ALL(allpaths));
    reverse(ALL(allpaths));
    if(allpaths.size() == 0){
        dp[s] = vals[s];
        fans = max(fans,dp[s]);
    }else if(allpaths.size() == 1){
        dp[s] = vals[s] + allpaths[0];
        fans = max(fans,dp[s]);
    }else{
         dp[s] = vals[s] + allpaths[0];
         fans = max(fans,vals[s] + allpaths[0] + allpaths[1]);
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
        cin >> x >> y; --x;--y;
        G[x].PB(y);
        G[y].PB(x);
    }
    for(int i=0;i<n;i++){
        cin >> vals[i];
    }
    dfs(0,-1);
    cout << fans << endl;
    
}