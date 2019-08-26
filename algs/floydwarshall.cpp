#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;

int N = 100;
const int inf = 1 << 20;
vector<vector<int>> ad(N, vector<int>(N, 0));

int main(){
    //fastio    
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    int n,m;
     cin >> n >> m;
    for (int i = 0; i < m; i++){
        int x, y , w;
        cin >> x >> y >> w;
        ad[--x][--y] = w;
        ad[y][x] = w;
    }
    for (int k = 0; k  < n;k++){
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                if(i!=j && j!= k && k!=i)
                    ad[i][j] = min(ad[i][j], ad[i][k] + ad[k][j]);
            }
        }
    }
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            cout << ad[i][j] << " ";
        }
        cout << endl;
    }
    
#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}