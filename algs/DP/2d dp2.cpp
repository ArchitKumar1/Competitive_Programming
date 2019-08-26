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


int N =  1000000;
vector<int> prime(N,1);
vector<int> primatic;

int main(){
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

   
    int n = 12345;

    auto karo =  [](){
        for(int i=2;i*i<=N;i++){
            if(prime[i] == 1){
                for(int j=i*i;j<N;j+=i){
                    prime[j]  =0;
                }   
            }
        }
        for(int i=2;i<N;i++){
            if(i < 10001 && prime[i]){
                primatic.push_back(i);
            }
        }
        primatic.push_back(4);
        primatic.push_back(27);
        primatic.push_back(256);
        primatic.push_back(3625);
    };
    karo();
    sort(ALL(primatic));

    vector<int> dp(n+1,inf);
    dp[0] = 0;
    for(int i=1;i<=n;i++){
        for(int c : primatic){
            if(i -c >=0){
                dp[i] = min(dp[i],dp[i-c] + 1);
            }
        }
    }
    TC{
        int x;
        cin >> x;
        cout << dp[x] << endl;
    }
    cout << primatic;

}