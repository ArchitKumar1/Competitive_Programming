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
    string s;
    cin >> s;
    string ops = "";
    vector<int> vals;
    int n = s.length();
    for ( char c : s){
        if(c == '+' || c == '*'){
            ops += c;
        }else{
            vals.PB(c-'0');
        }
    }
    int m = vals.size();
    int minv[m][m];
    int maxv[m][m];
    forn(i,m){
        forn(j,m){
            if(i != j){
                minv[i][j] = INT_MAX;
                maxv[i][j] = INT_MIN;
            }else{
                minv[i][j] = maxv[i][j] = vals[i];
            }
        }
    }
    
    for (int l = 1;l < m;l++){
        for (int i = 0; i + l < m;i++){
            int j = i + l;
            int b = INT_MAX;
            int a = INT_MIN;
            for (int k = i;k <j;k++){
                if(ops[k] == '+'){
                    a = max(a,maxv[i][k] + maxv[k + 1][j]);
                    b = min(b,minv[i][k] + minv[k + 1][j]);
                }else{
                    a = max(a,maxv[i][k] * maxv[k + 1][j]);
                    b = min(b,minv[i][k] * minv[k + 1][j]);
                }
            }
            maxv[i][j] = a;
            minv[i][j] = b;
        }
    }
    cout << maxv[0][m - 1] << " " << minv[0][m - 1] << endl;
    return 0;
}