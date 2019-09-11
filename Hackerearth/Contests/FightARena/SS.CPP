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
 
const int N = 12345;
int main(){
 
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    int n;
    cin >> n;
    int arr[n];
    forn(i,n) cin >> arr[i];
    vector<int> facts[N];
    set<int> ss[N];
    forn(i,n){
        set<int> temp;
        for(int j = 1;j*j<=arr[i];j++){
            if(arr[i]%j == 0){
                ss[i].insert(j);
                ss[i].insert(arr[i]/j);
                temp.insert(j);
                temp.insert(arr[i]/j);
            }
        }
        while(temp.size()){
            int t = *temp.begin();
            temp.erase(temp.begin());
            facts[t].PB(i);
        }
    }
    vector<int> fans(n);
    fans[0] = -1;
    for(int i=1;i<n;i++){
        vector<int> vtemp(ss[i].begin(),ss[i].end());
        reverse(ALL(vtemp));
        for(int c : vtemp){
            if(facts[c].size()){
                int low = 0;
                int tans = 0;
                int high = facts[c].size() - 1;
                while(low <= high){
                    int mid = (low + high)/2;
                    if(facts[c][mid]<i){
                        tans = mid;
                        low = mid+1;
                    }else{
                        high = mid-1;
                    }
                }
                fans[i] = (low+high)/2;
            }
        }
    }
    cout << fans;
    return 0;
}