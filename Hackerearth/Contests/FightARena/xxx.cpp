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

/////////////////////////////
const int N = 3500;
int g[N][N];


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    FASTIO
    TC{
        LL n,m,q;
        cin >> n >> m >> q;
        vector<LL> xx,yy,xs,ys;
        xx.PB(1);xx.PB(n);yy.PB(1);yy.PB(m);

        while(q--){
            LL x,y;cin >> x >> y;
            xx.PB(x);yy.PB(y);
        }
        sort(ALL(xx));sort(ALL(yy));
        xx.resize(distance(xx.begin(),unique(xx.begin(),xx.end())));
        yy.resize(distance(yy.begin(),unique(yy.begin(),yy.end())));
        
        for(LL i=1;i<xx.size();i++)xs.push_back(xx[i] - xx[i-1]);    
        for(LL i=1;i<yy.size();i++)ys.push_back(yy[i] - yy[i-1]);
        
        LL c = xs.size();
        LL d = ys.size();
        LL all = c*d;
        LL maxi = *max_element(ALL(xs)) ** max_element(ALL(ys));
        LL mini = *min_element(ALL(xs)) ** min_element(ALL(ys));
    
        cout << all << " " << mini << " " << maxi << endl;

    }

}