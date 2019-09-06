#include<bits/stdc++.h>
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){
    os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){
    return os<<"("<<P.first<<","<<P.second<<")";
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
		const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...) 1
#endif

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

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////

const int N = 123456;
const int K = 32;

int dp[K][N];
int arr[N];

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];
    }
    int k;
    cin >> k;
    dp[1][n-1] = 1;
    for(int i = 1;i<=30;i++){
        
        for(int j=n-1 - i +1;j>=0;j--){
            if(arr[j]!= 0){
                if(i == 1){
                    dp[i][j] = dp[i][j+1] + 1;
                }else{
                    dp[i][j] = dp[i][j+1] + dp[i-1][j+1];
                }
            }else{
                if(i == 1){
                    dp[i][j] = dp[i][j+1] + 1;
                }else{
                    dp[i][j] = dp[i][j+1];
                }
            }
        }
    }
    for(int i=0;i<32;i++){
        for(int j = 0;j<n;j++){
            cout << dp[i][j] << "  ";
        }
        cout << endl;
    }
    cout << dp[0][k-1] << endl;
    return 0;
}