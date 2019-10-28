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

const int mod = 99991;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


////////////////////////////
void print(int a[3][3]);


void mult(int a[3][3],int b[3][3]){
    //print(a);
    int c[3][3];
    forn(i,3){
        forn(j,3){
            c[i][j] = 0;
            forn(k,3){
                c[i][j] = (c[i][j]+((LL)a[i][k]*b[k][j])%mod)%mod;
            }
        }
    }
    forn(i,3)forn(j,3) a[i][j] = c[i][j];
    //print(a);
}
void print(int a[3][3]){
    forn(i,3){
        forn(j,3){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
int solve(LL n){
    if(n == -1) return 0;
    int base[3][3] ={{0,1,0},{0,0,0},{0,0,0}};
    int fib[3][3] ={{1,0,0},{1,1,1},{0,1,0}};
    while(n){
        if(n%2 == 1){
            mult(base,fib);
        }
        mult(fib,fib);
        n>>=1;
    }
    return base[0][0];

}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    
    

    LL l,r;
    cin >> l >> r;
    //trace(solve(r),solve(l-1));
    cout << solve(r) - solve(l-1);
    
    
}




