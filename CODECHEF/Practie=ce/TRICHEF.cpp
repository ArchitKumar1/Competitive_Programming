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
        vector<int> v1, v2, v3;
        for (int i = 0; i < n;i++){
            int x, y;
            cin >> x >> y;
            if(x == 1){
                v1.PB(y);
            }if(x == 2){
                v2.PB(y);
            }if(x == 3){
                v3.PB(y);
            }
        }
        sort(ALL(v1));
        sort(ALL(v2));
        sort(ALL(v3));
        vector<int> w1, w2, w3;
        for (int i; i < v1.size()- 1;i++){
            w1.PB(v1[i + 1] - v1[i]);
        }
        for (int i; i < v2.size()- 1;i++){
            w2.PB(v2[i + 1] - v2[i]);
        }
        for (int i; i < v3.size()- 1;i++){
            w3.PB(v3[i + 1] - v3[i]);
        }
        double ans1 = 0.0, ans2 = 0.0, ans3 = 0.0;
        int sas1 = 0,sas2 = 0,sas3 = 0;
        for (int i = 0; i < w1.size();i++){
            sas1 += w1[i] * (i + 1) * (n - i);
        }
        for (int i = 0; i < w2.size();i++){
            sas2 += w2[i] * (i + 1) * (n - i);
        }
        for (int i = 0; i < w3.size();i++){
            sas3 += w3[i] * (i + 1) * (n - i);
        }
        ans1 += (1.0)*(1 * sas1 + 2 * sas1) / 2;
        ans2 += (1.0)*(1 * sas2 + 2 * sas2) / 2;
        ans3 += (1.0)*(1 * sas3 + 2 * sas3) / 2;
        cout << ans1 + ans2 + ans3 << endl;
    }

    return 0;
}