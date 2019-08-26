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
int ispali[N][N];
int dp[N][N];

// int solve(string s,int i,int j){   
//     if(ispali[i][j]){
//         return dp[i][j] = 0;
//     }
//     else if(dp[i][j]) return dp[i][j];
//     else{
//         int ans = INT_MAX;
//         for (int k = i; k <= j - 1; k++)  {
//             ans = min(ans,solve(s,i,k) + 1 + solve(s,k+1,j));
//         }
//         return dp[i][j] = ans;
//     }
    
// }

int main(){
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

   string s;
   cin >> s;
   int n = s.length();

   

   for(int l=0;l<n;l++){
       for(int i = 0;i<n;i++){
           int j = i+l;
           if(i == j) ispali[i][j] = 1;
           else if(j == i+1){
               if(s[i] == s[j]){
                   ispali[i][j] = 1;
               }
           }else{
               if(s[i] == s[j] && ispali[i+1][j-1]){
                   ispali[i][j] = 1;
               }
           }

           if(i == j){
               dp[i][j] = 0;
           }else if(ispali[i][j]){
               dp[i][j] = 0;
           }else{
               int ans = INT_MAX;
               for(int k=i;k<=j-1;k++){
                   ans = min(ans,dp[i][k] + dp[k+1][j] + 1);
               }
               dp[i][j] = ans;
           }
       }
   }
   for(int i=0;i<n;i++){
       for(int j=0;j<n;j++){
           cout << dp[i][j] << " ";
       }
       cout << endl;
   }
   cout << dp[0][n-1] << endl;
   //cout << solve(s,0,n-1);

}