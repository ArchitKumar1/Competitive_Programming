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
#define REP(i,a,b) for(int i = a;i<=b;i++)

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

const int mod = 720720;
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
    LL n;
    cin >> n;
    LL k;
    cin >> k;
    vector<LL> arr(n);
    forn(i,n) cin >> arr[i];
    
    LL i = 0;
    vector<vector<LL>> vv(n,vector<LL>(3));
    forn(i,n){
        if(i<n/2){
            vv[i][0] = arr[i]^arr[n-i-1];
            vv[i][1] = arr[n-i-1];
            vv[i][2] = arr[i];
        }else{
            vv[i][0] = arr[n-i-1];
            vv[i][1] = arr[i]^arr[n-i-1];
            vv[i][2] = arr[i];
        }
    }
    // trace(vv);
    k--;
    for(LL i = 0;i<n;i++){
        if(i!= n-i-1){
            LL base =2;

            LL q = k/n;
            base += (q);
            base%= 3;
            
            LL rem = k%n;
           // rem = rem -1;
            if(rem>=i){
                base +=1;
                base%= 3;
            }
            // trace(q,rem,base);
            cout << vv[i][base] << " ";
        }else{
            if(k >= n/2){
                cout << "0" << " ";
            }else{
                cout << arr[i] << " ";
            }
        }
        
    }
    // i = 0;
    // forn(y,25){
    //     i = i%n;
    //     LL x = arr[i] ^ arr[n-i-1];
    //     //trace(arr[i],arr[n-i-1],x);
    //     arr[i] = x;
    //     trace(arr,i+1);
    //     i++;
    // }
    }
    return 0;
}




