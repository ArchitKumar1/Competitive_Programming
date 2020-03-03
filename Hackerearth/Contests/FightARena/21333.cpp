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


const int N = 1.1e5;

LL arr[N];
LL BIT[N][20];

int get(int x){
    set<char> s;
    string ss = to_string(x);
    for(char c : ss){
        s.insert(c);
    }
    return s.size();
}
void add(int i,int val,int d){
    while(i<N){
        BIT[i][d] += val;
        i += i&-i;
    }
}
LL query(int i,int d){
    LL res = 0;
    while(i>0){
        res = res+BIT[i][d];
        i-=i&-i;
    }
    return res;
}



int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    

    int n;
    cin >> n;
    for(int i=1;i<=n;i++){
        cin >> arr[i];
        add(i,1,get(arr[i]));
    }
    int q;
    cin >> q;
    while(q--){
        string s;
        LL u,v;
        cin >> s >> u >> v;
 
        if(s == "MAX"){
            int ans = 0;
            int d = 0;
            for(int i = 0;i<20;i++){
                int t = query(v,i) - query(u-1,i);
                if(t > 0) {
                    ans = t;
                    d  = i;
                }
            }
            cout <<d << " " << ans <<  endl;

        }else if(s == "MIN"){
            int ans = 0;
            int d = 0;
            for(int i = 19;i>=0;i--){
                int t = query(v,i) - query(u-1,i);
                if(t > 0) {
                    ans = t;
                    d  = i;
                }
            }
            cout <<d << " " << ans <<  endl;
        }else if(s == "REP"){
             add(u,-1,get(arr[u]));
             arr[u] = v;
             arr[u]%= mod;
             add(u,1,get(arr[u]));
        }else if(s == "ADD"){
            add(u,-1,get(arr[u]));
             arr[u] = (v+arr[u])%mod;
             add(u,1,get(arr[u]));
        }else{
            add(u,-1,get(arr[u]));
             arr[u] = (v*arr[u])%mod;
             add(u,1,get(arr[u]));
        }
    }
    
   

#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif

}