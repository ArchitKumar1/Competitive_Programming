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
map<pair<int, int>, int> m1;

bool check(int a,int b,int c,int d){
    return m1[{a + c, b + d}] == 1;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    TC{
        vector<PII> all;
        for (int i = 0; i < 5;i++){
            pair<int, int> t;
            cin >> t.F >> t.S;
            m1[t] = 1;
            all.PB(t);
        }
        bool ok = 0;
        for(auto p : all){
            PII curr = p;
            int a = curr.F;
            int b = curr.S;
           // DEBUG3(a, b, p.S);
             if(check(a,b,-1,0) && check(a,b,-2,0)&&check(a,b,0,-1) && check(a,b,0,1)) ok = 1;
            if(check(a,b,1,0) && check(a,b,2,0)&&check(a,b,0,-1) && check(a,b,0,1)) ok = 1;
            if(check(a,b,1,0) && check(a,b,-1,0)&&check(a,b,0,-1) && check(a,b,0,-2)) ok = 1;
            if(check(a,b,1,0) && check(a,b,-1,0)&&check(a,b,0,1) && check(a,b,0,2)) ok = 1;
            
        }
        m1.clear();
        if(ok == 1){
            cout << "Yes";
        }else{
            cout << "No";
        }
        cout << endl;
    }

}