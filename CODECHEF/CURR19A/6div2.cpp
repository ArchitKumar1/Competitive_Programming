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
   
   int t;
   cin >>t ;
   while(t--){
       int n,m;
       cin >> n >> m;
       vector<int> arr(n);
       for(int i=0;i<n;i++){
           cin >> arr[i];
       }
       vector<vector<int>> g(m);
       vector<pair<int,int>> every;
       for(int i=0;i<n;i++){
           int pos = i%m;
           g[pos].push_back(arr[i]);
           every.emplace_back(arr[i],i%m);
       }
       sort(every.begin(),every.end());
       deque<pair<int,int>> dq;
       int totalsum = 0;
       vector<int> checker(m,0);
       int fans = INT_MAX;
        map<int,int>m1;
       for(pair<int,int> p : every){  
           int i = p.second;
           int val = p.first;
               dq.push_back(p);
               m1[p.second]+=1;
               if(checker[i] == 0){
                   checker[i] =1;
                   totalsum+=1;
               } 
               while(m1[dq.front().second]>=2){
                   m1[dq.front().second]-=1;
                   dq.pop_front();
               }             
               if(totalsum == m)fans = min(fans,-dq.front().first + dq.back().first);
       }
       cout << fans << endl;
   }

}