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


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >>s;
    string c;
    cin >> c;
    char cc = c[0];
    int n;
    cin >> n;
    int ans = 1;
    int currmax= -1 ;
    int currans = 0;
    int l = s.size();
    for(int i=0;i<=l;i++){
        string x = s.substr(0,i) + c + s.substr(i,l);
        
        for(int j=0;j + n-1 < x.size();j++){
            string t = x.substr(j,n);
           // DEBUG2(i,t);
            int cnt =0 ;
            for(char the : t){
                if(the == cc){
                    cnt++;
                }
            }
            if(cnt>= currmax){
                if(i > currans ){
                    currans = i;
                }
                currmax= cnt;
            }
            //DEBUG1(cnt);
        }
    }
     cout << currans << endl;
}