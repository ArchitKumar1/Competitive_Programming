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




int ask(int l,int r){
    cout << "? " << l << " " << r << endl;
    int a; cin >> a;return a;
}


int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
    int n;
    cin >> n;
    
    int l = 1;
    int r = n;
    int ans[n+1] = {0};

    for(;r>1;r--){
        ans[r] = ask(l,r);
    }
    int ttt;
    ttt = ask(2,3);

    cout << "! ";

    int fans[n+1];
    for(int i = n;i>=3;i--){
        fans[i] = ans[i] - ans[i-1];
    }
    fans[1] = ans[3] - ttt;
    fans[2] = ans[n];
    for(int i =1;i<=n;i++){
        if(i!=2)
            fans[2]-=fans[i];
    }
    for(int i = 1;i<=n;i++){
        cout << fans[i] << " ";
    }
    cout << endl;

#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}