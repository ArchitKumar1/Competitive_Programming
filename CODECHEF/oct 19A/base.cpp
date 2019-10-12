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
#define REP(i,a,b) for(int i = a;i<=b;i++)

#define ALL(x) x.begin(),x.end()
#define LL long long int
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define endl "\n"
/////////////////////////////


LL eval(int base,string num){
    int res = 0;
    int pos = 0;
    for(int i = num.size()-1;i>=0;i--){
        char c = num[i];
        int t = 0;
        if(c >='A' && c <='Z'){
            t = 10 + (int) ( c - 'A');
        }else{
            t = (int)(c -'0');
        }
        //trace(t,base,pos);
        res += t * pow(base,pos);
        pos++;
    }
    return res;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    //trace(eval(26,"10000"));
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        pair<int,string> all[n];
        for(int i=0;i<n;i++){
            cin >> all[i].first >> all[i].second ;
        }
        map<LL,int> m1[n];
        for(int i=0;i<n;i++){
            if(all[i].first == -1){
                for(int j=1;j<=36;j++){
                    //trace(j,all[i].second);
                    //trace(i,j,eval(j,all[i].second));
                    m1[i][eval(j,all[i].second)] = 1;
                }
            }else{
                m1[i][eval(all[i].first,all[i].second)] =1;
            }
        }
        LL fans = -1;
        vector<LL> mat;
        
        forn(i,n){
            for(auto x : m1[i]){
                trace(x);
                if(x.S == 1){
                    mat.PB(x.F);
                }
            }
        }
        for(LL c : mat){
            bool ok = 1;
            forn(i,n){
                if(m1[i][c] != 1){
                    ok = 0;
                }
            }
            if(ok == 1){
                cout << c << endl;
            }
            break;
        }
        cout << fans << endl;
    }
    
    return 0;
}




