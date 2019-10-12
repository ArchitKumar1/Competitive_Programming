#include<bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os,vector<T> V){
    os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(onstream &os,pair<L,R> P){
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
vector<int> primes{2,3,5,7,11,13,17,19,23,29,31,37,41,43,47};
int n;

vector<vector<int>> dp;

int maxval = (1 << 15) -1;

int solve(int mask,int curr,VI &arr){
    if(curr == n) return 0;
    if(dp[mask][curr] != -1) return dp[mask][curr];

    int ways = solve(mask,curr+1,arr);

    if(arr[curr] == 1){
        return dp[mask][curr] = ways + 1;
    }
    LL newmask = mask;
    bool ok = 1;
    forn(i,15){
        if((arr[curr]%primes[i] == 0) ){
            if(newmask &(1 << i)) return dp[mask][curr] = ways;
            newmask |= (1 << i);
        }
    }
    return dp[mask][curr]= max(ways,1 + solve(newmask,curr+1,arr));
    
    
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    TC{
        
        cin >> n;
        VI arr(n);
        forn(i,n){
            cin >> arr[i];
        }
        //sort(ALL(arr));
        dp.assign((1 << 16),vector<int>(60,-1));

        cout <<  solve(0LL,0,arr) << endl;
    }
    
    return 0;
}




