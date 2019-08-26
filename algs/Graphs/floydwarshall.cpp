
#include <bits/stdc++.h>
using namespace std;
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vii;
#define INF 0x3f3f3f3f



void floyd(int n,vector < vector<int>> &e){
    for (int i = 0; i < n;i++){
        e[i][i] = 0;
    }
    for (int k = 0;k<n;k++){
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                e[i][j] = min(e[i][j], e[i][k] + e[k][j]);
            }
        }
    }
}
int main() {

#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    vector < vector<int>> e(n, vector<int>(n, INF));
    

    for (int i = 0; i < n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        e[x][y] = z;
        e[y][x] = z;
    }
    floyd(n,e);
    for (int i = 0; i < n;i++){

        cout << e[0][i] << " ";
    }
        return 0;
}