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
 
 

int main(){
 
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    int n,m;
    cin >> n >> m;
    string g[n];
    forn(i,n) cin >> g[i];

    auto safe = [&](int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    };
    int dx[4] = {0,1,0,-1};
    int dy[4]= {1,0,-1,0};
    int ans =0;
    int X;
    int Y;
    int len;
    forn(i,n) forn(j,m){
        if(g[i][j] == 'B') continue;
        char c = g[i][j];
        int tans = INT_MAX;
        int pans = 0;
        forn(k,4){
            int cnt = 0;
            int  I = i;
            int J = j;
            
            while(safe(I,J)&& g[I][J] == 'G'){
                cnt++;
                I+= dx[k];
                J+= dy[k];
            }    
            //trace(i,j,cnt);
            tans = min(tans,cnt);

        }
        //trace(i,j,tans);
        int area = 4*tans -3;
        if(area > ans){
            X = i;
            Y = j;
            len = tans;
            ans = area;
        }
        
    }
    for(int i = X;i<X+len;i++) g[i][Y] = 'B';
    for(int i = X;i>X-len;i--) g[i][Y] = 'B';
    for(int j = Y;j>Y-len;j--) g[X][j] = 'B';
    for(int j = Y;j<Y+len;j++) g[X][j] = 'B';

    int ans2 = 0;

    forn(i,n) forn(j,m){
        if(g[i][j] == 'B') continue;
        char c = g[i][j];
        int tans = INT_MAX;
        forn(k,4){
            int cnt = 0;
            int  I = i;
            int J = j;
            
            while(safe(I,J)&& g[I][J] == 'G'){
                cnt++;
                I+= dx[k];
                J+= dy[k];
            }    
            //trace(cnt);
            tans = min(tans,cnt);

        }
        //trace(i,j,tans);
        if(tans %2 == 1){
            tans-=1;
        }
        int area = 4*tans -3;
        ans2 = max(ans2,area);
    }
    forn(i,n){
        cout << g[i] << endl;
    }
    cout << max(1,ans) * max(1,ans2) << endl;
    trace(ans,ans2);
    return 0;
}