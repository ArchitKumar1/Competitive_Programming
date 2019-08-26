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

const int N = 1234567;
vector<LL> prime(N, 1);
vector<LL> all;

void seive(){
    for (int i = 2; i * i <=N;i++){
        if(prime[i] == 1){
            for (int j = i * i; j <N;j = j+i){
                prime[j] = 0;
            }
        }
    }
    for (int i = 1; i < N;i++){
        if(prime[i]){
            all.PB(i);
        }
    }
}
bool isprime(LL a){
    if(a == 1 || a == 0) return 0;
    for(LL i : all){
        if(i>=2 && a%i == 0) return 0;
    }return 1;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    seive();
    TC{
        LL n;
        cin >> n;
        LL ans = 0;
        for(LL i : all){
            if(n%i == 0){
                ans = max(ans, i);
                if(isprime(n/i)){
                    ans = max(ans,n/i);
                }
            }
        }
        cout << ans << endl;
    }
}