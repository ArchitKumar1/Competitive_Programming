#include<bits/stdc++.h>
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){return os<<"("<<P.first<<","<<P.second<<")";}
#define DEBUG1(x) cout  << '>' << " " << #x << ':' << " " <<  x << endl;
#define DEBUG2(x,y) cout  << '>' << " " << #x << ':' << " " <<  x <<  " " << #y << ':' << " " <<  y <<endl;
#define DEBUG3(x,y,z) cout  << '>' << " " << #x << ':' << " " <<  x << " " << #y << ':' << " " <<  y <<" " << #z << ':' << " " <<  z << " " <<endl;
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

const int mod = 10*9+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

void splitter(string s,vector<string> &ans){
    stack<char> st;
    string base = "";
    for(char c : s){
        if(c == '('){
            st.push('(');
            base += '(';
        }else{
            st.pop();
            base += ')';
            if(st.empty()){
                ans.push_back(base);
                base = "";
            }
        }
    }
}
int solve(string s){
    int n = s.length();
    cout << s << endl;
    if(s == "()"){
        return 1;
    }
    vector<string> base;
    splitter(s,base);
    if(base.size() == 1){
        s.erase(0,1);
        s.erase(s.size()-1,1);
        return 2 * (solve(s));
    }
    int ans = 0;
    for(string c : base){
        ans +=  solve(c);
    }
    return ans;
}

int main(){
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    string s;
    cin >> s;
    cout << solve(s) << endl;
    
}