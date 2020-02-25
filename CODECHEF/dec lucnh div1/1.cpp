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

const int mod = pow(10,9)+7;
const double inf = 1e18;
const LL linf = 2e18;
const double eps = 1e-9;

//////////////////////////////////////////////

const int N = 1.3e6;

bool pali(int n){
    string s = to_string(n);
    string t = s;
    reverse(ALL(t));
    return s == t;
}
string odd(string s){
    string t = s;
    reverse(ALL(t));
    t.erase(t.begin());
    string ans = s + t;
    return ans;
}
string even(string s){
    string t = s;
    reverse(ALL(t));
    string ans = s + t;
    return ans;
}
string gen_pali(LL n){
    if(n<=10) return to_string(n-1);
    string s = to_string(n);
    if(s[0] == '1' && s[1] == '0'){
        string half = "9";
        for(int i =2;i<s.size();i++){
            half += s[i];
        }
        return odd(half);
    }
    if(s[0] == '1'){
        string half = "";
        for(int i =1;i<s.size();i++){
            half += s[i];
        }
        return even(half);
    }else{
        string half = "";
        half += (s[0] -1); 
        for(int i =1;i<s.size();i++){
            half += s[i];
        }
        return odd(half);
    }
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
FASTIO
    TC{
        LL n;
        cin >> n;
        LL k;
        cin >> k;

        LL l = 0;
        LL h = 1e9;

        LL ans = -1;
        while(l<=h){
            LL mid = (l+h)/2;
            string palin = gen_pali(mid);
            LL num = stoll(palin);
            if(num >= n){
                ans = mid;
            h = mid-1;
            }else{
                l = mid+1;
            }
        }
        trace(ans,gen_pali(ans));
        trace(ans+k,gen_pali(ans+k));
        cout << gen_pali(ans+k -1) << endl;
    }

#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}