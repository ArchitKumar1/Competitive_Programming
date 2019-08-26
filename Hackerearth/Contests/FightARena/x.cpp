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
    TC{
        int n;
        cin >> n;
        int k;
        cin >> k;
        int arr[n];
        int cnt = 0;
        int  ocnt = 0;
        forn(i,n){
            int x;
            cin >> x;
            if(x == k){
                cnt++;
            }else{
                ocnt++;
            }
        }
        LL ans = 0;
        LL fans = 0;
        int all = ocnt + cnt;
        if(cnt <3 || ocnt + cnt < 3){
            ans = 0;
        }else{
            ans += (LL) cnt*(cnt-1)*(cnt-2)/6;
            fans += (LL) all*(all-1)*(all-2)/6;
        }
        LL g = __gcd(ans,fans);
        ans = ans/g;
        fans = fans/g;
        cout << ans << "/" << fans << endl; 
    }
}