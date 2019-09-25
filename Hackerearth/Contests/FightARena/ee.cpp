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

const LL N = 2e9+100;
int main(){
 
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    vector<LL> all;
    for(int i=2;i*i<=N;i++){
        LL base = i;
        LL b = i;
        while(b*base <=N){
            b = b*base;
            all.PB(b);
        }
    }

    sort(ALL(all));
    all.resize(unique(all.begin(),all.end()) - all.begin());
    TC{
        int q;
        cin >> q;
        while(q--){
            int n;
            cin >> n;
            int l = 0;
            int h = all.size() - 1;
            int pos;
            while(l<=h){
                int mid = (l+h)/2;
                if(all[mid] >= n){
                    pos = mid;
                    h = mid-1;
                }else{
                    l = mid+1;
                }
            }
            int ans = min(abs(all[pos] - n),min(abs(all[pos+1] - n),abs(all[pos-1] -n)));
            cout << ans << endl;
        }
    }
    return 0;
}