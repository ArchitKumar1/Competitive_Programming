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

int gcd(int a,int b){
    if(a == 0)
        return b;
    if(b == 0)
        return a;
    if( a > b)
        return gcd(a % b, b);
    else
        return gcd(a, b % a);
}

void solve(){
    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    vector<int> brr(arr.begin(), arr.end());
    sort(ALL(brr));
    vector<int> crr(n);

    for (int i = 0; i < n;i++){
        if(arr[i] == brr[i]){
            continue;
        }else{
            swap(arr)
        }
    }
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