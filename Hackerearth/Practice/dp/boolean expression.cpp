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
 
const int mod = pow(10,9) +9;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;
 
 
/////////////////////////////
 
 
const LL N = 350;
LL arr[N];
LL dptrue[N][N];
LL dpfalse[N][N];
 
int main(){
 
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    string a;
    string b;
    cin >>a >> b;
 
    for(LL i=0;i<a.length();i++){
        arr[i] = a[i] - '0';
    }
    LL n = a.length();
 
    
    for(LL i=0;i<n;i++){
        dptrue[i][i] = arr[i];
        dpfalse[i][i] = arr[i]^1;
    }
    for(LL l=1;l<n;l++){
        for(LL i = 0;i+l<n;i++){
            LL j = i+l;
            LL t = 0,f = 0;
            for(LL k = i;k<j;k++){
                
                if(b[k] == 'a'){
                    t+= (LL)dptrue[i][k] * dptrue[k+1][j]; t%= mod;
                    f+= (LL)dpfalse[i][k] * dptrue[k+1][j];f%= mod;
                    f+= (LL)dptrue[i][k] * dpfalse[k+1][j];f%= mod;
                    f+= (LL)dpfalse[i][k] * dpfalse[k+1][j];f%= mod;
                }else if(b[k] == 'o'){
                    t+=(LL) dptrue[i][k] * dptrue[k+1][j]; t%= mod;
                    t+= (LL)dpfalse[i][k] * dptrue[k+1][j];t%= mod;
                    t+= (LL)dptrue[i][k] * dpfalse[k+1][j];t%= mod;
                    f+= (LL)dpfalse[i][k] * dpfalse[k+1][j];f%= mod;
                }else{
                    t+=(LL) dpfalse[i][k] * dptrue[k+1][j];t%= mod;
                    t+= (LL)dptrue[i][k] * dpfalse[k+1][j];t%= mod;
                    f+=(LL) dptrue[i][k] * dptrue[k+1][j];f%= mod;
                    f+=(LL) dpfalse[i][k] * dpfalse[k+1][j];f%= mod;
                }
            }
            dptrue[i][j] = t;
            dpfalse[i][j] = f;
        }
    }
    // for(LL i=0;i<n;i++){
    //     for(LL j=0;j<n;j++){
    //         cout << dptrue[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    // for(LL i=0;i<n;i++){
    //     for(LL j=0;j<n;j++){
    //         cout << dpfalse[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    LL q;
    cin >> q;
    while(q--){
        LL x,y;
        cin >> x >> y;
        --x;--y;
        string temp ;
        cin >> temp;
        if(temp == "true"){
            cout << dptrue[x][y] << endl;
        }else{
            cout << dpfalse[x][y] << endl;
        }
    }
    return 0;
}