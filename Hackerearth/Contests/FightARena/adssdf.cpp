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
   
  
    int n,m;
    cin >> n>> m;
    int arr[n][m];
    forn(i,n)forn(j,m)cin >> arr[i][j];
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        int r=-1,c=-1;
        forn(i,n){
            int l = 0;
            int h = m-1;
            int ans = -1;
            while(l<=h){
                int mid = (l+h)>>1;
                if(arr[i][mid] == x){
                    ans = mid;
                    break;
                }else if(arr[i][mid] > x){
                    h = mid-1;
                    
                }else{
                    l = mid+1;
                    
                }
            }
            if(ans !=-1){
                r= i;
                c = ans;
            }
        }
        cout << r << " "<<c << endl;
    }
   

}