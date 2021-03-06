#include<bits/stdc++.h>
#pragma GCC optimize()
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

const int mod = pow(10,9) +9;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

const int N = 2e6+10;

vector<vector<int>> curr(N);
vector<vector<int>> facts(N);

void process(int n){
    for(int i =1;i*i<=n;i++){
        if(n%i == 0){
            facts[n].PB(i);
            if(i != n/i){
                facts[n].PB(n/i);
            }
        }
    }
}
/////////////////////////////

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
FASTIO

    int n;
    cin >> n;
    vector<int> arr(n);
    forn(i,n)cin >> arr[i];

    forn(i,n){
        process(arr[i]);
    }

    int fans = INT_MIN;
    forn(i,n){
        fans = max(fans,(int)curr[arr[i]].size());
        for(int c : facts[arr[i]]){
            curr[c].PB(arr[i]);
        }
        
    }
    cout << fans << endl;
    

    
    // 7
    // 8 1 28 4 2 6 7
    // 3
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    
    return 0;
}




