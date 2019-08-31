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


const int N = 1000;
int g[N][N];
 int n;
int ans = 0;

bool safe(int i,int j){
    return i>=0 && j>=0 && i<n && j<n;
};
int fans = 0;
void dfs(int i,int j){
    if(!safe(i,j)) return ;
    if(g[i][j] == 1){
        ans ++;
        g[i][j] = 0;
        dfs(i+1,j);
        dfs(i-1,j);
        dfs(i,j-1);
        dfs(i,j+1);
    }
    
}
int main(){
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

  
    cin >> n;
    forn(i,n) forn(j,n) cin >> g[i][j];

    forn(i,n) forn(j,n){
        if(g[i][j] == 1){
            ans = 0;
            dfs(i,j);
            
            fans = max(fans,ans);
        }
    }
    cout << fans << endl;
}