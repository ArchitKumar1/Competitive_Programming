#include<bits/stdc++.h>
#pragma optimize("O3","-ofast")
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


inline bool vow(char c){
    return (c == 'a' || c == 'e' || c == 'i' || c == 'o'||c=='u');
}

double calc(double a,int b){
    double base = 1.0;
    while(b){
        if(b&1) base = base*a;
        a = a*a;
        b>>=1;
    }
    return base;
}
int main(){
    FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
     cout.precision(8);cout << fixed;
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        string a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        int indcnt[2][26]={0};
        int totalcnt[2][26]={0};
        int ta=0,tb=0;
        for(string s : a){
            vector<int> cnt1;
            for(int j = 0;j<s.size();j++){
                if(!vow(s[j])){
                    cnt1.push_back(j);
                }
            }
            bool ok = 1;
            for(int i=1;i<(int)cnt1.size();i++){
                if(cnt1[i] - cnt1[i-1]<=2){
                    ok =0;
                }
            }
            if(ok == 0) tb +=1;
            else ta+=1;
            vector<int> change(26,0);
            
            for(char c : s){
                change[c-'a'] = 1;
                totalcnt[ok][c-'a']+=1;
                
            }
            for(int i=0;i<26;i++){
                indcnt[ok][i]+=change[i];
            }
        }
        double fans = 0.0;
        for(int i =0;i<26;i++){
            if(totalcnt[1][i]!=0){
                fans += log10(indcnt[1][i]);
                fans -= ta*log10(totalcnt[1][i]);
            }
            if(totalcnt[0][i]!=0){
                fans -= log10(indcnt[0][i]);
                fans += tb*log10(totalcnt[0][i]);
            }
        }
        fans = pow(10,fans);
        if(fans > 1e7){
            cout << "Infinity" << endl;
        }else{
            cout << fans <<endl;
        }
        
    }
}