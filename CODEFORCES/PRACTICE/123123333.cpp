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

const int N = 26;
int par[N];
int size[N];

int find(int v){
    if(v == par[v]) return v;
    else return par[v] = find(par[v]);
}
void merge(char x,char y){
    int a = find(x-'a');
    int b = find(y-'a');
    if(a !=b){
        if(size[a] < size[b]) swap(a,b);
        par[b] = a;
        size[a] += size[a];
    }
}

int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
    int n;
    cin >> n;
    forn(i,N){
        par[i] = i;
        size[i] = 0;
    }
    vector<string> all(n);
    forn(i,n) cin >> all[i];
    forn(i,n){
        for(char c : all[i]){
            size[c-'a'] = 1;
        }
    }
    forn(j,n){
        for(int i=0;i+1<all[j].size();i++){
            merge(all[j][i],all[j][i+1]);
        }
    }
    map<int,int> m1;
    for(int i=0;i<N;i++){
        if(size[find(i)]!=0)
        m1[par[i]]+=1;
    }
    int cnt = 0;
    for(auto x : m1){
        if(x.S>=1){
            cnt++;
        }
    }
    cout << cnt << endl;
    

#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}