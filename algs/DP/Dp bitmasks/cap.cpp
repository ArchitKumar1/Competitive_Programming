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
 
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
 
#define ALL(x) x.begin(),x.end()
#define LL long long int
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define endl "\n"
 
typedef pair<int,int>PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<PII> VPII;
 
const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;
 
 
/////////////////////////////
 
const int N = 123;
vector<vector<int>>caps;
int n;
int dp[1200][200];

int solve(int personmask,int curr_cap){
    if(personmask == ((1 << n) -1) ) return 1;
    if(curr_cap > 100) return  0;

    if(dp[personmask][curr_cap] != -1) return dp[personmask][curr_cap];

    int ans = 0 ;
    ans += solve(personmask,curr_cap+1);
    ans%= mod;
    for(int i : caps[curr_cap]){
        if(!(personmask &(1 << i))){
            ans += solve(personmask | (1 <<i),curr_cap+1);
            ans%= mod;
        }
    }
    return dp[personmask][curr_cap] = ans;

}

int main(){
 
FASTIO    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    TC{
        memset(dp,-1,sizeof(dp));
        caps.assign(N,vector<int>());
        cin >> n;
        string temp,str;
        getline(cin,str);
        forn(i,n){
            getline(cin,str);
            stringstream ss(str);
            while(ss >> temp){

                stringstream s;
                s << temp;
                int x;
                s >> x;
                caps[x].PB(i);
            }
        }
        cout << solve(0,1) << endl;
        // for(int i=1;i<=100;i++){
        //     if(caps[i].size()){
        //         trace(i,caps[i]);
        //     }
        // }
        
        
    }
    
    // for(int i=1;i<=100;i++){
    //     for(auto x : caps[i]){
    //         cout << i << " " << x.first << endl;
    //     }
    // }
    
    return 0;
}