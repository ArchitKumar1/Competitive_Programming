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

bool ischar(char c){
    return (c >= 'a' && c <= 'z');
}

bool isnum(char c){
    return (c<='9' && c>='0');
}
LL multiply(string a,string b){
    LL A = 1;
    LL B = 1;
    if(a!=""){
        A = stoll(a);
    }
    if(b!=""){
        B= stoll(b);
    }
    trace(A*B);
    return A*B;
}
int main(){
 
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    string s;
    cin >> s;
    LL n = s.length();
    vector<pair<char,LL>>v1;
    for(LL i=0;i<n;i++){
        char c = s[i];
        if(ischar(c) && c!='x'){
            LL val = 0;
            string mul1;
            string mul2;
            LL j = i;
            while(j+1<n && isnum(s[j+1])){
                mul1+=s[j+1];
                j++;
            }
            if(j+1 <n && s[j+1] == 'x'){
                j++;
                while(j+1<n && isnum(s[j+1])){
                    mul2+=s[j+1];
                    j++;
                }
            }
            //trace(mul1,mul2,multiply(mul1,mul2));
            v1.PB({c,multiply(mul1,mul2)});
        }
    }
    //trace(v1);
    map<char,LL> m1;
    for(auto p : v1){
        m1[p.first]+= p.second;
    }
    vector<pair<char,LL>> all;

    for(auto p : m1){
        all.PB({p.first,p.second});
    }
    sort(ALL(all));
    //trace(all);
    vector<LL> cum(all.size(),0);
    cum[0] = all[0].second;
    for(LL i =1;i<cum.size();i++){
        cum[i] = cum[i-1] + all[i].second;
    }
    //trace(cum);
    LL q;
    cin >> q;
    while(q--){
        LL pos;
        cin >> pos;
        LL low = 0;
        LL fans =-1;
        LL high = cum.size()-1;
        while(low<=high){
            LL mid = (low + high)/2;
            if(pos <= cum[mid]){
                //trace(mid,cum[mid]);
                fans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        if(fans == -1){
            cout << "-1" << endl;
        }
        else cout << all[fans].first << endl;

    }
    return 0;
}