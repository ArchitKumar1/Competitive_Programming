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

int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
    string s;
    cin >> s;
    int n = s.length();
    int total = 0;


    
    for(int i=0;i<n;i++){
        int odd = 0,even = 26;
        string temp = "";
        vector<int> alphacount(26,0);
        for(int j=i;j<n;j++){
            int length_of_substring = j-i+1;
            temp+=s[j];
            alphacount[s[j]-'a']+=1;
            if(alphacount[s[j]-'a']%2 == 0){
                even+=1;
                odd-=1;
            }else{
                odd+=1;
                even+=1;
            }
            if(length_of_substring%2 == 0){
                if(odd == 0){
                    total+=1;
                }
            }else{
                if(odd==1){
                    total+=1;
                }
            }
        }
    }
    cout << total << endl;

   #ifndef ONLINE_JUDGE
        cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
    #endif

}