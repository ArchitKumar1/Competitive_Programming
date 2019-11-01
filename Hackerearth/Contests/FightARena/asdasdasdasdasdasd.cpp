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
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


////////////////////////////

int n;
int pos = 1;
vector<pair<int,int>> inorder;
int arr[1234567];
void dfs(int s){
    if(s >n) return;
    dfs(2*s);
    inorder.EB(arr[s],pos++);
    dfs(2*s+1);
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    

   cin >> n;
   
   forn(i,n){
       cin >> arr[i+1];
   }
   dfs(1);
    sort(ALL(inorder));
    int cnt = 0;
    vector<int> vis(n+1,0);
    for(int i=1;i<=n;i++){
        if(inorder[i-1].S  == i || vis[i] == 1){
            vis[i] =1;
        }
        else{
            int j = i;
            int cyclelen = 0;
            while(vis[j] == 0){
                vis[j] =1;
                j = inorder[i-1].S;
                cyclelen++;
            }
            cnt+= cyclelen-1;
        }
    }
    cout << cnt << endl;
}




