#include<bits/stdc++.h>
using namespace std;

#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)



/////////////////////////////

const int N = 12345;
vector<int> dis1,dis2;
vector<vector<int>> G;

void dfs1(int s,int par,int dist){
    dis1[s] =dist;
    for(int c: G[s]){
        if(c == par ) continue;
        dfs1(c,s,dist+1);
    }
}
void dfs2(int s,int par,int dist){
    dis2[s] =dist;
    for(int c: G[s]){
        if(c == par ) continue;
        dfs2(c,s,dist+1);
    }
}
int main(){
 #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    TC{
        int n,q;
        cin >> n >> q;
        G.assign(n+1,vector<int>());
        forn(i,n-1){
        int x,y;
            cin >> x>> y;
            x--;y--;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        while(q--){
            int a,da,b,db;
            cin >> a >> da >> b >> db;
            a--;b--;
            dis1.assign(n,0);
            dis2.assign(n,0);
            dfs1(a,-1,0);
            dfs2(b,-1,0);
            int ans = -1;
            forn(i,n){
                if(dis1[i] == da && dis2[i] == db){
                    ans = i+1;
                    break;
                }
            }
            cout << ans << endl;
        }
    }
    
   
    return 0;
}



