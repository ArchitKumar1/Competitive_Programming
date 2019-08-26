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

/////////////////////////////////

const int N = 100;

void solve(){
    int n,m;
    cin >> n >> m;
    VVI dist(N, VI(N, -inf));
    forn(i,n){
        dist[i][i] = 0;
    }
    forn(i,m){
        int x, y, z;
        cin >> x >> y >> z;
        x--;y--;
        dist[x][y] = z;
        dist[y][x] = z;
    }
    bool ok = 1;
    for (int k = 0; k < n;k++){
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                if(dist[i][k] + dist[k][j] < dist[i][j]){
                    DEBUG3(dist[i][k], dist[j][k], dist[i][j]);
                    ok = 0;
                    break;
                }
            }
        }
    }
    cout << (ok == 1 ? "POSSIBLE" : "NOTPOSSILBE") << endl;
}
int main()
{
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int t = 1;
    cin >> t;
    while(t--)
        solve();

#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;    
            
}