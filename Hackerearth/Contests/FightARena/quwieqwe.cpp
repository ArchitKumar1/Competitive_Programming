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

int dx[4] ={0,1,0,-1};
int dy[4] = {1,0,-1,0};

int fans =0 ;
map<pair<int,int>,int> m1;


int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    

    string s;
    cin >> s;
    map<char,int> m2;
    m2.insert({'R',0});
    m2.insert({'D',1});
    m2.insert({'L',2});
    m2.insert({'U',3});
    int n = s.length();
    pair<int,int> init ={0,0};
    m1[init] = 1;
    forn(i,n){
        
        init.F += dx[m2[s[i]]];
        init.S += dy[m2[s[i]]];
        if(m1[init]) fans +=1;
        m1[init] = 1;
        //trace(init);
    }
    cout << fans << endl;

    

}