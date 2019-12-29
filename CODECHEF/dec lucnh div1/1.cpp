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

vector<LL> get(LL n){
    vector<LL> all;
    for(LL i =1;i*i<=n;i++){
        if(n%i == 0){
            all.PB(i);
            if(n/i != i){
                all.PB(n/i);
            }
        }
    }
    return all;
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
FASTIO
    TC{
        LL a,m;
        cin >> a >> m;
        vector<LL> all = get(m);
        vector<LL> ans ;
        for(LL c : all){
            LL bacha = m-c;
            if(bacha%a != 0) continue;
            bacha = bacha/a;
            if(bacha%c == 0){
                if(bacha!=0)ans.PB(bacha);
            } 
        }
        //cout << all << endl;
       sort(ALL(ans));
        cout << ans.size() << endl;
        for(LL c : ans){
            cout << c << " ";
        }cout << endl;
    }

#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}