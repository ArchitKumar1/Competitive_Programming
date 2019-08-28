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


int solve(string s,int i,int j){
    if(i > j) return 0;
    if(i == j){
        return 1;
    }
    if(s[i] == s[j]){
        return solve(s,i+1,j) + solve(s,i,j-1) + 1;
    }
    else{
        return solve(s,i+1,j) + solve(s,i,j-1) - solve(s,i+1,j-1);
    }
}
int main(){
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    int n = s.length();
    
    int dp[n][n];
    forn(i,n) forn(j,n) dp[i][j] = 0;
    
    for(int l=0;l<n;l++){
        for(int i =0;i<n;i++){
            int j = i+l;
            if(i == j){
                dp[i][j] = 1;
            }else{
                if(s[i] == s[j]){
                    dp[i][j] = 1 + dp[i+1][j] + dp[i][j-1];
                }else{
                    dp[i][j] = dp[i+1][j] + dp[i][j-1] - dp[i+1][j-1];
                }
            }
        }
    }
    cout << dp[0][n-1] << endl;
}