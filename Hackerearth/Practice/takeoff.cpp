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

const int N = 1e5 + 100;

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    LL n,q;
    cin >> n >> q;
    LL  arr[n];
    LL  brr[n];
    forn(i, n) cin >> arr[i];
    forn(i, n) cin >> brr[i];

    LL  newarr[n], newbrr[n];
    LL pos = 0;
    for (int i = 0; i < n;i++){
        if(i%2 == 0){
            newarr[i] = arr[pos++];
        }else{
            newarr[i] = brr[pos++];
        }
    }
    pos = 0;
    for (int i = 0; i < n;i++){
        if(i%2 == 0){
            newbrr[i] = brr[pos++];
        }else{
            newbrr[i] = arr[pos++];
        }
    }
    LL dparr[n+1], dpbrr[n+1];
    dparr[0] = 0;
    dpbrr[0] = 0;
    for (int i = 0; i < n;i++){
        if(i == 0){
            dparr[i+1] = newarr[i];
        }else{
            dparr[i+1] = newarr[i] + dparr[i];
        }
    }
    for (int i = 0; i < n;i++){
        if(i == 0){
            dpbrr[i+1] = newbrr[i];
        }else{
            dpbrr[i+1] = newbrr[i] + dpbrr[i];
        }
    }
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;

        if(t == 1){
            if(l%2 == 0)
                cout << dpbrr[r] - dpbrr[l - 1] << endl;
            else
                cout << dparr[r] - dparr[l - 1] << endl;
        }else{
            if(l%2 == 0)
                cout << dpbrr[r] - dpbrr[l - 1] << endl;
            else
                cout << dparr[r] - dparr[l - 1] << endl;
        }
    }

#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
}