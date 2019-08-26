#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 32;
int bo[N][N];
int mar[N][N];
int n;
int dx[8] = {1, 2, 2, 1, -1, -2, -2, -1};
int dy[8] = {2, 1, -1, -2, -2, -1, 1, 2};

void dfs(int i,int j){
    if(i >= 0  && i<n && j >= 0 && j< n){
        if(!mar[i][j]){
            mar[i][j] = 1;
            for (int k = 0; k < 8;k++){
                dfs(i + dx[k], j + dy[k]);
            }
        }
    }

}
void solve(){
    cin >> n;
    memset(mar, 0, sizeof(mar));
    memset(bo, 0, sizeof(bo));
    int x, y;
    cin >> x >> y;

    dfs(--x, --y);
    double ans = 1.0 * n * n;
    int cnt = 0;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            if(mar[i][j]){
                cnt++;
            }
        }
    }
    cout.precision(2);
    cout << fixed << cnt * 100  / ans << endl;

}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}