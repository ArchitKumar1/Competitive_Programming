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

const int mod = pow(10,9)+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;



int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    TC{
        int n;
        cin >> n;
        int x = 0;
        int y = 0 ;
        char cc[n][n];
        forn(i,n) forn(j,n){
            cin >> cc[i][j];
            if(cc[i][j] == '*'){
                x = i;
                y = j;
            }
        }
        cout << abs(x - n/2) + abs(y - n/2) << endl;
    }
}