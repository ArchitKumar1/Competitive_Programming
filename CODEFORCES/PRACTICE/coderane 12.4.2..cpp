#include<bits/stdc++.h>
using namespace std;


#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)


const int inf = 1e9;



int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    
    TC{
        int n,m;
        cin >> n >> m;
        char grid[n][3*m];
        vector<int> g[n];
        for(int i=0;i<n;i++){
            for(int j=m;j<2*m;j++){
                cin >> grid[i][j];
                grid[i][j-m] = grid[i][j];
                grid[i][j+m] = grid[i][j];
            }
        }
        vector<int> all[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<3*m;j++){
                if(grid[i][j] == 'M'){
                    all[i].push_back(j);
                }
            }
        }
        int dist[n][3*m];
        memset(dist,inf,sizeof(dist));
        for(int i=0;i<n;i++){
            //trace(all[i]);
            if(all[i].size() == 0){
                for(int j=m;j<2*m;j++){
                    dist[i][j] = inf;
                }
                continue;
            }
            for(int j=0;j+1<all[i].size();j++){
                //trace(all[i][j],all[i][j+1]);
                for(int k = all[i][j];k<=all[i][j+1];k++){
                    dist[i][k] = min(abs(k-all[i][j]),abs(k-all[i][j+1]));
                }
            }
        }
        // for(int i=0;i<n;i++){
        //     for(int j=m;j<2*m;j++){
        //         cout << dist[i][j];
        //     }
        // }
        int best_shift= INT_MAX;
        for(int j=m;j<2*m;j++){
            int curr_shift = 0;
            for(int i=0;i<n;i++){
                curr_shift+= dist[i][j];
            }
            best_shift =min(best_shift,curr_shift);
        }
        if(best_shift>=inf){
            cout << "-1" << endl;
        }else{
            cout << best_shift << endl;
        }

            
        
    }


#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}