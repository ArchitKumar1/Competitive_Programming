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


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    forn(i, n) cin >> arr[i];

    int dp[n][n];
    int mark[n][n];
    memset(dp, 0, sizeof(dp));
    memset(mark, 0, sizeof(mark));
    for (int i = 0; i < n;i++){
        dp[i][i] = n*arr[i];
    }
    for (int l = 1; l < n;l++){
        for (int i = 0; i + l < n;i++){
            int j = i + l;
            int year = n - (j - i);
            int x = arr[i] * year + dp[i + 1][j];
            int y = year * arr[j] + dp[i][j - 1];
            dp[i][j] = max(x, y);
            if( x > y){
                mark[i][j] = 1;
            }else if(x < y ){
                mark[i][j] = -1;
            }else{
                mark[i][j] = 0;
            }
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cout << mark[i][j] << " ";
        }
        cout << endl;
    }
    cout << dp[0][n - 1] << endl;
    int i = 0;
    int j = n - 1;
    while( i <=j){
        if(mark[i][j] ==1){
            i++;
            cout << "beg  ";
        }else if(mark[i][j] == -1){
            cout << "end ";
            j--;
        }else{
            i++;
            cout << "beg ";
        }
    }
    return 0;
}