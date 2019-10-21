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

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)



const int mod = pow(10,9) +7;
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
        int n,k;
        cin >> n >> k;
        string ans = "";
        vector<string>all(n);
        forn(i,n) cin >> all[i];
        
        for(int i=0;i<k;i++){
            int val = 0;
            int ftemp = INT_MAX;
            for(int a = 0;a<26;a++){
                int temp = 0;
                for(int j =0 ;j<n;j++){
                    temp += abs(a - (all[j][i] - 'a'));
                    //trace(all[j][i],abs(a - (all[j][i] - 'a')),j);

                }
                //trace(temp,a,i);
                if(temp < ftemp){
                    ftemp = temp;
                    val = a;
                }
            }
            ans += (char)('a' + val);
            
        }
        cout << ans << endl;
    }
    
}




