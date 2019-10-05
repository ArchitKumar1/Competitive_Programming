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

const int size = 22;
const int all = (1 << size) -1;
vector<int> arr(all + 10);
vector<int> brr(all + 10,-1);
unordered_map<int,int> m1;

int main(){
 FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    int n;
    cin >> n;
    forn(i,n) {
        cin >> arr[i];
        brr[arr[i]] = arr[i];
    }
    forn(i,all+1){
        if(brr[i] == -1){
            forn(j,size){
                if((i & (1 << j)) != 0){
                    int  mask = i ^ (1 << j);
                    if(brr[mask]!=-1){
                        //trace(i,mask);
                        brr[i] = brr[mask];
                        j = size;
                    }
                }
            }
        }
    }
    // for(int i =0 ;i<100;i++){
    //     trace(brr[i],i);
    // }
    forn(i,n){
        cout << brr[all - arr[i]]  << " ";
    }
    

    
    
    return 0;
}