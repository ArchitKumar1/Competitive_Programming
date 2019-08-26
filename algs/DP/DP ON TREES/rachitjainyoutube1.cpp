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
vvi e(N);

int dp1[N], dp2[N];
int coins[N];
void dfs(int s,int par){
    int sum1 = 0, sum2 = 0;

    for (int c: e[s]){
        if(c == par) continue;
        dfs(c, s);
        sum1 += dp2[c];
        sum2 += max(dp1[c], dp2[c]);
    }
    dp1[s]= coins[s] + sum1;
    dp2[s] = sum2;
}
int main(){
    fastio    
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;

    for (int i = 0; i < n-1;i++){
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    for (int i = 0; i < n;i++){
        cin >> coins[i];
    }
        dfs(0, -1);
    cout << max(dp1[0], dp2[0]);

#ifndef ONLINE_JUDGE
		cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}