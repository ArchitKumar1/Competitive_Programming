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

map<vector<int>, int> m1;
int compute(VI curr,int s){
    if(s == 2){
        return curr[0] + curr[1];
    }else{
        int n = curr.size();
        int ans = INT_MAX;
        for (int i = 0; i < s;i++){
            int start = i;
            int end = (i + 1) % s;
            int cost = curr[start] + curr[end];
            vector<int> newcurr(curr.begin(), curr.end());
            newcurr[start] = newcurr[start] + newcurr[end];
            
            newcurr.erase(newcurr.begin() + end);
            if(m1[newcurr] == 0){
                m1[newcurr] =  compute(newcurr, s - 1);

            }
            ans = min(ans, cost + m1[newcurr]);
        }
        return ans;
    }
}
void solve(){
    int n;
    cin >> n;
    VI arr(n);
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    cout << compute(arr,n) << endl;
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    TC{
        solve();
    }
#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
}