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
FASTIO  
    

    TC{
        string s;
        cin >> s;
       
        stack<char> st;
        string pref;
        for(char c : s){
            if(st.size() <=1){
                st.push(c);
            }
            else{
                char first = st.top();st.pop();
                if(st.top() == c){
                    
                    pref += first;
                    continue;
                }else{
                    st.push(first);
                    st.push(c);
                }
            }
        }
        vector<char> seq;
        map<char,int> m1;
        
        while(st.size()){
            seq.PB(st.top());
            m1[st.top()]+=1;
            st.pop();
        }
       
        bool ok = 1;
        
        for(auto x : m1){
            if(x.S >=2){
                cout << "NO" << endl;
               ok = 0;
            }
        }
        reverse(ALL(seq));
        trace(seq);
        trace(pref);
        for(char c : pref){
            m1[c] +=1;
        }

        if(ok == 0)continue;
        cout << "YES" << endl;
        cout << pref;
        for(char c : seq){
            cout << c;
        }
        for(char c = 'a';c<='z';c++){
            if(m1[c]!=1)cout << c;
        }
        cout << endl;
        //A:
    }
    

#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}