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

int main(){
 
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    

    TC{
        int index,n;
        cin >> index >> n;
        
        vector<vector<double>> a(n+1,vector<double>(3,0.0));
        a[0][index] = 1.0;

        for(int i = 1;i<=n;i++){
            for(int j = 0;j<3;j++){
                
                if(j == 0){
                    a[i][j]+=a[i-1][1]/2;
                    //a[i][j]+=a[i-1][2]/2;
                }else if(j == 1){
                     a[i][j]+=a[i-1][0]/2;
                    a[i][j]+=a[i-1][2]/2;
                }else{
                    // a[i][j]+=a[i-1][0]/2;
                    a[i][j]+=a[i-1][1]/2;
                }
                
            }
            double total = accumulate(ALL(a[i]),0.0);
            for(int j = 0;j<3;j++){
                a[i][j] /= total;
            }
        }
        for(auto c : a){
            cout << c << endl;
        }
        vector<pair<double,int>> temp;
        for(int i =0 ;i<3;i++){
            temp.PB({1e5/a[n][i],i});
        }
        sort(ALL(temp));
        cout << temp[0].S << endl;
    }
    return 0;
}