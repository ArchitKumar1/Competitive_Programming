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



int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
   int n;
   cin >> n;
   
   string s[n];
   for(string &a : s){
       cin >> a;
   }
   map<int,int> m1;
   for(string a : s){
        string x = a.substr(0,2);
        string y = a.substr(6,2);
        string x1 = a.substr(3,2);
        string y1 = a.substr(9,2);
       int c = stoi(x);
       int d = stoi(y);
       int c1 = stoi(x1);
       int d1 = stoi(y1);
       //trace(c,d,c1,d1);
       m1[c*60+c1]+=1;
       m1[d*60+d1]-=1;
   }
   int pos = 0;
   bool ok = 0;
   for(auto x : m1){
       //trace(x);
       pos += x.S;
       ok |= (pos >1);
   }
    if(ok == 1){
        cout << "Will need a moderator!" << endl;
    }else{
        cout << "Who needs a moderator?" << endl;
    }

}