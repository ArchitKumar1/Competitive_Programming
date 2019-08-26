#include<bits/stdc++.h>
using namespace std;
const int N = 410;
const int inf = 1e9;
int dist[N][N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0;i<N;i++){
        for (int j = 0; j < N;j++){
            if(i == j)dist[i][j] = 0;
            dist[i][j] = inf;
        }
    }
    int m;
    cin >> m;
    while(m--){
        int x,y,z;
        cin >> x >> y >> z;
        dist[x][y] = z;
    }
    for (int k = 1;k<=n;k++){
        for (int i = 1; i <= n;i++){
            for (int j = 1; j <= n;j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }
    int q;
    cin >> q;
    while(q--){
        int x,y;
        cin >> x >> y;
        (dist[x][y] == inf) ? cout << "-1" : cout << dist[x][y];
        cout << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    solve();
    return 0;
}