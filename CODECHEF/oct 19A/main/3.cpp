#include<bits/stdc++.h>
using namespace std;

vector<vector<int >> graph_full;
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int m;
        cin >> m;
        int x = 20;
        int y= 40;
        int graph[x][y];
        for(int i=0;i<x;i++){
            for(int j=0;j<y;j++){
                graph[i][j] = n+m;
            }
        }
        graph_full.clear();
        graph_full.assign(n,vector<int>());
        for(int i=0;i<m;i++){
            int x,y;
            cin >> x >> y;
            --x;--y;
            graph_full[x].push_back(y);
            graph_full[y].push_back(x);
        }
        if(m%2 == 0){
            cout << "1" << endl;
            for(int i=0;i<n;i++)cout << "1 ";
            cout << endl;
        }else{
            int flagger_checker = -1;
            for(int i=0;i<n;i++){
                if(graph_full[i].size()%2 == 1){
                    flagger_checker = i;
                    i = n;
                }
            }
            if(flagger_checker!=-1){
                cout << "2" << endl;
                for(int i=0;i<n;i++){             
                    if(i!= flagger_checker)cout << "1 "; 
                    else cout << "2 ";   
                }
                cout << endl;
            }else{
                int first_val,sec_val;
                int init = 0;
                for(int i  = 0;i<n &&(init== 0);i++){
                    if(graph_full[i].size()>=2){
                        first_val = i;
                        sec_val = graph_full[i][0];
                        init = 1;
                    }
                }
                cout << "3" << endl;
                for(int i=0;i<n;i++){
                    if(i == first_val)  cout << "3 ";
                    else if(i == sec_val) cout << "2 ";
                    else cout << "1 ";  
                }
                cout << endl;
            } 
            for(int i=0;i<x;i++){
                for(int j=0;j<y;j++){
                    graph[i][j] = n+m;
                }
            }    
        }  
    }
    return 0;
}
