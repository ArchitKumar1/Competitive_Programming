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


int count(string &s){
    int cnt = 0;
    for(int i=0;i+1<s.size();i++){
        if(s[i] == s[i+1]) cnt++;
    }
    return cnt;
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif 
FASTIO  
    // TC{
    // string s;
    // cin >> s;
    // string tt ;
    // tt =s;
    // int n = s.length();
    // int total =0;
    // for(int i =0;i<n;i++){
    //     for(int j=i;j<n;j++){
    //        // trace(i,j);
    //         for(int z =i;z<=j;z++){
    //             if(s[z] == '0') s[z] = '1';
    //             else s[z] = '0';
    //         }
    //       //  trace(i,j,s);
    //      //   trace(count(s));
    //         total +=count(s);
    //         s = tt;
    //     }
        
    // }
    // cout << total << endl;
    // }
    TC{
        string s;
        cin >> s;
        LL cnt = count(s);

        LL fans = 0;
        LL same = 0;
        LL diff = 0;
        LL n = s.length();
        for(LL i=0;i+1<s.size();i++){
            if(s[i] == s[i+1]) same +=1;
            else diff +=1;            
        }
        cnt = same;
        LL total = (LL)cnt*n*(n+1)/2 - (same*(same-1)) + diff*(diff-1) +2*diff - 2*same;
        cout << total << endl;
    }
#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}