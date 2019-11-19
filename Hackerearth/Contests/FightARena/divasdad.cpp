#include<bits/stdc++.h>
#pragma optimize("O3","-ofast")
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

int n,k;
const int N = 123456;
vector<vector<int>> G(N);
int arr[N];

LL tcnt = 0;
void dfs(int s,int par,map<int,int> &m1,int curr = 0){
    //trace(s);
    int xor1 = curr ^arr[s];
    int ff = xor1 ^ k;
    tcnt += (LL)m1[ff];
    if(xor1 == k) tcnt += 1;
    //trace(m1[ff],xor1,ff,tcnt);
    m1[xor1] +=1;
    for(int c : G[s]){
        if(c == par ) continue;
        dfs(c,s,m1,xor1);
    }
    m1[xor1]-=1;
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
    
   cin >> n >> k;
   forn(i,n) cin >> arr[i];
    forn(i,n-1){
        int x;
        cin >> x;
        G[x-1].PB(i+1);
    }
    map<int,int> m1;
    dfs(0,-1,m1);
    cout << tcnt << endl;


    

}