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
int a[N][N][N],dp[N][N][N];

int main(){
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

   int arr[3][3][3] = { { {1, 2, 4}, {3, 4, 5}, {5, 2, 1}}, 
    { {4, 8, 3}, {5, 2, 1}, {3, 4, 2}}, 
    { {2, 4, 1}, {3, 1, 4}, {6, 3, 8}} 
  }; 
    int n = 3;
    forn(i,n){
        forn(j,n){
            forn(k,n){
                a[i+1][j+1][k+1] = arr[i][j][k];
            }
        }
    }
    for(int i =0;i<=n;i++){
        for(int j =0;j<=n;j++){
            for(int k =0;k<=n;k++){
                dp[i][j][k] = inf;
            }
        }
    }
    for(int i =0;i<=n;i++){
        for(int j =0;j<=n;j++){
            for(int k =0;k<=n;k++){
                if(i == 0 || j==0 || k == 0) dp[i][j][k] = 0;
                else{
                    dp[i][j][k] = a[i][j][k] + min(dp[i-1][j][k],min(dp[i][j-1][k],dp[i][j][k-1]));
                    DEBUG2(a[i][j][k],dp[i][j][k]);
                    DEBUG3(i,j,k);
                }
                
            }
        }
    }
    for(int i =1;i<=n;i++){
        for(int j =1;j<=n;j++){
            for(int k =1;k<=n;k++){
                cout << dp[i][j][k] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << endl;
    }
    cout << dp[3][3][3] << endl;

}