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
#define ALL(x) x.begin(),x.end()
#define LL long long int
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define endl "\n"
#define l() cout << endl;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)

const int mod = pow(10,9)+7;
const double inf = 1e18;
const LL linf = 2e18;
const double eps = 1e-9;

//////////////////////////////////////////////

string bin(int n){
    string ans ="";
    while(n){
        ans += ('0' + (n&1));
        n = n/2;
    }
    reverse(ALL(ans));
    return ans;
}
int comp(int a,int b){
    int cnt = 0;
    while(b){
        ++cnt;
        int u = a^b;
        int v = a&b;
        a = u;
        b = 2*v;
    }
    return cnt;
}
int randint(){
    return (pow(2,15)*((rand())%(int)(pow(2,15))) + rand()%(int)pow(2,15));
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    srand(time(NULL));
    int T = 1e7;
    int ans = INT_MIN;
    while(T--){
        ans = max(ans,comp(randint(),randint()));
    }
    cout << ans << endl;

   #ifndef ONLINE_JUDGE
        cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif

}