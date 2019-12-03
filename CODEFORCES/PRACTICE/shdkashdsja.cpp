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

int n,k;
const int N= 2e5;
vector<vector<int>> G(N),cumc(N);
vector<int> terms(N),allc(N);
int fans = 0;

void dfs1(int s,int par){
    for(int c : G[s]){
        if(c == par)continue;
        dfs1(c,s);
        allc[s] += allc[c];
        if(allc[c]!=0)cumc[s].PB(allc[c]);
    }
    if(terms[s] == 1)allc[s] +=1;
}

void dfs2(int s,int par){
    if(terms[s] != 1){
        if(s!=0){
            cumc[s].PB(allc[0] - allc[s]);
        }
        //trace(s,cumc[s]);
        int total = 0;
        for(int x : cumc[s]){
            total += x;
        }
        if(total >=3 && cumc[s].size()>=2){
            fans += 1;
        }
    }
    for(int c : G[s]){
        if(c == par) continue;
        dfs2(c,s);
    }
}
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   

    cin >> n >> k;
    forn(i,n-1){
        int x,y;
        cin >> x>> y;
        x--;y--;
        G[x].PB(y);
        G[y].PB(x);
    }
    forn(i,k){
        int x;
        cin >> x;
        terms[x-1] = 1;
        fans +=1;
    }
    dfs1(0,-1);
    dfs2(0,-1);
    cout << fans << endl;

    // forn(i,n){
    //     trace(i+1,cumc[i]);
    // }

    return 0;
}