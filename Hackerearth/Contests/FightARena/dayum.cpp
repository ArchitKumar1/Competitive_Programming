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
        int n,d,r;
        cin >> n >> d >> r;
        string numstream = to_string(n);
        int rem = 0;
        int curr = 0;
        int pos = 0;
        bool flag = 0;

        int fans = 0;
        int dig = 0;
        bool start = 0;
        while(1){
            //trace(dig,fans);
            if(start == 1){
                if(dig > r){
                    break;
                }
            }
            if(d > curr){
                if(pos >=numstream.size()){
                    start= 1;
                    curr=curr*10;
                }else{
                    curr= curr*10;
                    curr+=(numstream[pos]-'0');
                    pos++;
                }
                if(flag == 0){
                    flag = !flag;
                }else{
                    fans  =0;
                    if(start) dig++;
                }
                
            }else{
                 rem = curr%d;
                 //trace(stoi(curr)/d);
                 fans = curr/d;
                 curr = rem;
                 flag = 0;
                 if(start)dig++;
            }
            //trace(curr);
        }
        cout << fans << endl;
    }
    
}




