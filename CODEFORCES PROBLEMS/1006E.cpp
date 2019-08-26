#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb(x) push_back(x)
using namespace std;

const int N = 2e5 +10;
vector<int> e[N];
int pre[N];
int rev[N];
int cnt = 0;
int chil[N];

void dfs(int s,int par){
    int ch = 1;
    pre[++cnt] = s;
    rev[s] = cnt;
    for (auto c : e[s]){
        if(c == par) continue;
        dfs(c,s);
        ch+= chil[c];
    }
    chil[s] += ch;
}
int main()
{
    fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n,q;
	cin >> n >> q;
    for (int i = 2; i <=n;i++){
        int x;
        cin >> x;
        e[x].push_back(i);
    }
    for (int i = 0; i < n;i++){
        sort(e[i].begin(), e[i].end());
    }
    dfs(1,-1);

    for (int i = 0; i < q;i++){
        int x, y;
        cin >> x >> y;
        if(chil[x] < y){
            cout << "-1" << endl;
        }
        else{
            cout << pre[rev[x] + y - 1] << endl;
        }
    }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
