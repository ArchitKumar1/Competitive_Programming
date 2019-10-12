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


int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    TC{
        LL n,m;
        cin >> n>> m;
        LL N = max(n,m);
        vector<pair<LL,LL>> hori(m,{0,m});
        vector<pair<LL,LL>> verti(n,{0,n});
        
        LL q;
        cin >> q;

        LL totaleven = n*m;
        LL totalodd = 0;

        while(q--){
            LL x,y;
            cin >> x >> y;
            
            --x;--y;
            trace(x,y);
            bool ok = 0;
            if(hori[x].F<hori[x].S) ok =1;
            swap(hori[x].F,hori[x].S);

            if(ok == 1) hori[x].F--,hori[x].S++;
            else hori[x].F++,hori[x].S--;

            totalodd += hori[x].F;
            totalodd -=hori[x].S;
            ok = 0;
            if(verti[y].F<verti[y].S) ok =1;
            swap(verti[y].F,verti[y].S);

            if(ok == 1) verti[y].F--,verti[y].S++;
            else verti[y].F++,verti[y].S--;

            totalodd += verti[x].F;
            totalodd -= verti[x].S;
            trace(hori,verti);
        }
        cout << totalodd << endl;
    }
    
    return 0;
}




