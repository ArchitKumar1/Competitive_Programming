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


const int N =3234;
int arr[N];
int dp[N][N];

int solve(int s,int e,int year){
    if(s == e){
        return dp[s][e] = year * arr[s]; 
    }
    if(dp[s][e]) return dp[s][e];
    else return dp[s][e] = max(arr[s]*year + solve(s+1,e,year+1),arr[e]*year +solve(s,e-1,year+1));
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
FASTIO
   
    int n;
    n = 30;
    for(int i=0;i<n;i++){
        arr[i] = i+1;
    }
    //cout << solve(0,n-1,1);
    int dp[n][n];
    for(int l= 0;l<n;l++){
        for(int i=0;i+l<n;i++){
            int j = i+l;
            int year = n - (j-i);
            if(i == j) dp[i][j] = year*arr[i];
            else dp[i][j] = max(arr[i]*year + dp[i+1][j] ,arr[j]*year + dp[i][j-1]);
        }
    }
    cout << dp[0][n-1] << endl;
        
}