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

void solve(){
    int a,b,c;
    cin >> a >> b >> c;
    VI arr(a), brr(b), crr(c);
    forn(i, a) cin >> arr[i];
    forn(i, b) cin >> brr[i];
    forn(i, c) cin >> crr[i];
    sort(ALL(arr));sort(ALL(brr));sort(ALL(crr));
    set<int> s1(ALL(arr)),s2(ALL(brr)), s3(ALL(crr));
    VI arr2(ALL(s1)), brr2(ALL(s2)), crr2(ALL(s3));
    LL ans = 0;
    for (int i = 0; i < brr2.size(); i++){
        auto l = upper_bound(ALL(arr2), brr2[i]);
        auto r = upper_bound(ALL(crr2),  brr2[i]);
        //DEBUG2(l - arr2.begin(), r - crr2.begin());
        ans += (LL)(l - arr2.begin()) * (r - crr2.begin());
    }
    cout << ans << endl;
}
int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //srand (time(NULL));
    int t = 1;
    //cin >> t;
    while(t--){
        solve();
    }

}