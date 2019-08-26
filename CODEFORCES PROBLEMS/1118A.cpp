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

const int N = 100000;
vector<int> a(N);
vector<vector<int>> e(N);
vector<int> dp(N);

void dfs(int s,int par){
    int x;
    int y = a[s];
    for(auto c : e[s]){
        if(c == par)
            continue;
        dfs(c, s);
        x = max(x, dp[c]);
    }
}

int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    for (int i = 0; i < n - 1;i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    dfs(0, -1);
    cout << dp[0];
    
#ifndef ONLINE_JUDGE
		cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}