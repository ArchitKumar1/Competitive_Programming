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

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    LL n;
    cin >> n;
    LL arr[n];
    for (LL i = 0; i < n;i++){
        cin >> arr[i];
    }
    LL ufans = 0;
    LL mele = *max_element(arr, arr + n);
    LL total = (LL)n * (n + 1) / 2;
    LL mbit = log2(mele) + 1;
    LL s = 0;
    for (LL i = 0; i < mbit;i++){
        LL x = 0;
        LL fans = 0;
        LL cnt = 1;
        LL sum = 0;
        vector<LL> temp;
        for (LL j = 0; j < n;j++){
            if(!((arr[j] >> i)&1)){
                temp.PB(j);
            }
        }
        for (LL j = 1; j < temp.size();j++){
            if(temp[j] - temp[j-1] == 1){
                cnt++;
            }else{
                fans += cnt * (cnt + 1) / 2;
                cnt = 1;
            }
        }
        fans +=(LL) cnt *( cnt+1) / 2;
        fans = total - fans;
        ufans += fans*pow(2,i);
        temp.clear();
        }
    cout << ufans << endl;
}