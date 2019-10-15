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




int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    TC{

        int n; cin >> n;
        int m; cin >> m;
        
        vector<vector<int>>G(n);
        int parent[n+1] = {0};
        int flag=0;
        int counter = 1;
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x;cin >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if(m%2==0){
            cout<<"1"<<endl;
            for(int i=1;i<=n;i++) cout<<"1 ";
            cout<<endl;
        }
        else
        {
            counter = 2;
            for(int i=1;i<=n;i++)
            {
                if(G[i].size()%2==1)
                {
                    parent[i] = -1;
                    flag=1;
                    break;
                }
            }
            if(flag==0)
            {
                counter = 3;
                int hold = 0;
                for(int i=1;i<=n && hold==0;i++)
                {
                    for(int j=0;j<G[i].size() && G[i].size()>=2;j++)
                    {
                        int val1 = G[i][j];
                        G[val1].erase(find(G[val1].begin(), G[val1].end(),i));
                        hold=1;
                    }
                    if(hold==1)
                    {
                        parent[i] = -2;
                        G[i].clear();
                        //counter=2;
                    }
                }
                for(int i=1;i<=n;i++)
                {
                    if(G[i].size()%2==1)
                    {
                        parent[i] = -1;
                        flag=1;
                        break;
                    }
                }
            }
            cout<<counter<<endl;
            for(int i=1;i<=n;i++)
            {
                if(parent[i]==-1)
                {
                    cout<<"2 ";
                }
                else if(parent[i]==-2)
                {
                    cout<<"3 ";
                }
                else
                {
                    cout<<"1 ";
                }
            }
            cout<<endl;
        }
    }
}