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

typedef pair<int,int>PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<PII> VPII;

const int mod = 720720;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////

vector<int> in,vis;
vector<vector<int>> G;

vector<int> curr;

void dfs(int s){
    curr.PB(s);
    vis[s] =1;
    for(int c : G[s]){
        if(vis[c] == 0) dfs(c);
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    TC{
        int n;
        cin >> n;
        int m;
        cin >> m;
        bool staff = 0;
        
        in.clear();
        vis.clear();
        G.clear();
        curr.clear();
        in.assign(n,0);
        vis.assign(n,0);
        G.assign(n,vector<int>());

        for(int i=0;i<m;i++){
            int x,y;
            cin >> x >> y;
            --x;--y;
            in[x]++;
            in[y]++;
            G[x].PB(y);
            G[y].PB(x);
        }
        if(m%2 == 0){
            cout << "1" << endl;
            forn(i,n){
                cout <<"1 ";
            }
            cout << endl;
            continue;
        }
        vector<vector<pair<int,int>>> allo;
        int odd = 0;
        forn(i,n){
            if(vis[i] == 0){
                curr.clear();
                dfs(i);

                int total = 0;
                for(int c : curr){
                    total += in[c];
                    //trace(c,in[c]);
                }
                vector<pair<int,int>> combo;
                for(int c : curr){
                    combo.PB({in[c],c});
                }
                total=total/2;
                if(total%2 == 1){
                    odd++;
                    allo.PB(combo);
                }
            }
        }
        if(odd%2 == 0){
            cout << "1" << endl;
            forn(i,n){
                cout << "1 ";
            }
            cout << endl;
        }else{
            bool ok = 0;
            int temp1;
            for(int i =0 ;i<(int)allo.size();i++){
                for(pair<int,int> x : allo[i]){
                    if(ok == 0){
                        if(x.F%2 == 1){
                            temp1 = x.S;
                            ok = 1 ;
                            i =allo.size();
                        }
                    }
                }
            }
            if(ok == 1){
                cout << "2" << endl;
                for(int i =0;i<n;i++){
                    if(i!= temp1){
                        cout << "1 ";
                    }else{
                        cout << "2 ";
                    }
                }
                cout << endl;
            }else{
                int temp2  = allo[0][0].S;
                int temp3  = allo[0][1].S;
                
                cout << "3" << endl;
                forn(i,n){
                    if(i == temp2){
                        cout << "2 ";
                    }else if(i == temp3){
                        cout << "3 ";
                    }else{
                        cout << "1 ";
                    }
                }
                cout << endl;
            }

        }

        
    }
    return 0;
}




