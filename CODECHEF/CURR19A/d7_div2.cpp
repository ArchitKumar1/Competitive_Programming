#include<bits/stdc++.h>
using namespace std;

const int inf = 1e9;
vector<vector<int>> G;
vector<int> indeg;
vector<vector<int>> connectedcomps;
vector<int> vis;
vector<int> ccpos,totale;
vector<int> temp;

void dfs(int s){
    temp.push_back(s);
    vis[s] =1;
    for(int c : G[s]){
        if(vis[c]==0)
            dfs(c);
    }
}

void solve(){
    int n,m;
    cin >> n >> m;
    G.assign(n,vector<int>());
    indeg.assign(n,0);
    connectedcomps.clear();
    vis.assign(n,0);
    
    for(int i=0;i<m;i++){
        int x,y;
        cin >> x>> y;
        --x;--y;
        indeg[x]++;indeg[y]++;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    // for(int i=0;i<n;i++){
    //     if(vis[i] == 0){
    //         temp.clear();
    //         dfs(i);
    //         connectedcomps.push_back(temp);
    //         temp.clear();
    //     }
    // }
    // // for(auto x : connectedcomps){
    // //    for(auto y : x){
    // //        cout << y << " ";
    // //    }
    // //    cout << endl;
    // // }
    // int nc = connectedcomps.size();
    //cout << "NC : " << nc << endl;
     
    
    //  ccpos.assign(nc,0);
    // totale.assign(nc,0);
    // for(int i=0;i<nc;i++){
    //     int total_edges = 0;
    //     for(int y : connectedcomps[i] ){
    //         total_edges +=indeg[y];
    //     }
    //     total_edges/=2;
    //     totale[i] = total_edges;
    //     if(total_edges >= (int)connectedcomps[i].size()){
    //         ccpos[i] = 1;
    //     }
    // }
    // int allones = count(ccpos.begin(),ccpos.end(),1);
    // int fans = inf;
    // bool ok = 0;
    // if(allones<=1){
    //     for(int i=0;i<nc;i++){
    //         if(ccpos[i] == 1){
    //             for(int x : connectedcomps[i]){
    //                 //cout << temp << " " << indeg[x] << endl;
    //                 if((totale[i]-indeg[x]) < ((int)connectedcomps[i].size()-1)){
    //                     //cout << "P : " << x+1 << endl;
    //                     ok|=1;
    //                     fans = min(fans,x+1);
    //                 }
    //             }
    //         }
            
    //     }
    // }
    bool ok = 0;int fans = 1e9;
    if(m>=n){
        for(int i=0;i<n;i++){
            //trace(m,indeg[i],n-1);
            if(m-indeg[i] < (n-1)){
                ok = 1;
                fans = min(fans,i+1);
            }
        }
    }
    if(ok ==1){
        cout << fans <<endl;
    }else{
        cout << "-1" << endl;
    }
            
    
}
int main(){+
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
       int t;
    cin >> t;
    while(t--){
        solve();
    }
}