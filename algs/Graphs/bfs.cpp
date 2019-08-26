#include<bits/stdc++.h>

using namespace std;

const int N = (int)3e3 + 10;

vector<int> e[N], vis(N), par(N);
queue<int> q;


void bfs(int s ){
    vis[s] = 1;
    par[s] = -1;
    q.push(s);
    while(!q.empty()){
        int u = q.front();
        q.pop();
        for (int c : e[u]){
            if(!vis[c]){
                vis[c] = 1;
                q.push(c);
                par[c] = u;
            }
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    for (int i = 0; i < n - 1;i++){
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int s ;
    cin >> s;
    bfs(s);
    vector<int> path;

    for (int i = 0; i < n;i++){
        path.clear();
        for (int j = i; j != -1;j = par[j]){
            path.push_back(j);
        }
        cout << "Path for " << i << "  : ";
        reverse(path.begin(), path.end());
        for (int x : path){
            cout << x << " ";
        }
        cout << endl;
    }
        return 0;

}