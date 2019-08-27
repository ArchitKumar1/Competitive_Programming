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

const int N = 1234;
int g[N][N];
int dp[N][N];

int getsum(int x1,int y1,int x2,int y2){
    
    return (dp[x1][y1] - dp[x2-1][y1] -dp[x1][y2-1] + dp[x2-1][y2-1]);
}
int main(){
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n,m; cin >> n >> m;
    int q;
    cin >> q;
    for(int i=1;i<=n;i++){
        string x ;
        cin >> x;
        for(int j=1;j<=m;j++){
            g[i][j] = x[j-1] - '0';
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            dp[i][j] = g[i][j] + dp[i-1][j] + dp[i][j-1] -dp[i-1][j-1];
        }
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=m;j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    int x1,y1,x2,y2;
    int c1,d1,c2,d2;
    x1 = 1;
    y1 = 1;
    x2 =  n;
    y2 = n;
    c1= x1;
    c2 = x2;
    d1 = y1;
    d2 =y2;
    cout << x1 << " " << y1 << endl;
    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int x,y;
            cin >> x >> y;
            c1 = c1-x;
            d1 = d1-y;
            c2 = c1 + n;
            d2 = d1 + n;
            int A,B,C,D;
            DEBUG2(c1,d1);
            A= max(c1,x1);
            B= max(d1,y1);
            C= min(c2,x2);
            D= min(d2,y2);
            DEBUG2(A,B);
            DEBUG2(C,D);
           // cout << getsum(C,D,A,B) << endl;
        }else{
            int A,B,C,D;
            DEBUG2(c1,d1);
            A= max(c1,x1);
            B= max(d1,y1);
            C= min(c2,x2);
            D= min(d2,y2);
            cout << getsum(C,D,A,B) << endl;
        }
    }
}