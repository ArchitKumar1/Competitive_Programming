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

/////////////////////////////

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    TC{
        int n;
        cin >> n;
        priority_queue<int> p1, p2;
        for (int i = 0; i < n;i++){
            int x;
            cin >> x;
            if(i%2 == 0){
                p1.push(x);
            }else{
                p2.push(x);
            }
        }
        int a = 0, b = 0;
        while(p1.size() && p2.size()){
            int x = p1.top();
            p1.pop();
            int y = p2.top();
            p2.pop();
            x > y ? ++a : ++b;
        }
        if(a == b){
            cout << "draw" << endl;
        }else if(a < b){
            cout << "2" << endl;
        }else{
            cout << "1" << endl;
        }
    }

    return 0;
}