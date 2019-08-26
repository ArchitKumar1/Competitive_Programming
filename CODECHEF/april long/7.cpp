#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
#define pb(x) push_back(x)
using namespace std;
const int inf = 1 << 30;

vector<pair<pair<int, int>,int>> e;
vector<int> dist;



void bell(int s ,int n ){

    dist.assign(n, inf);
    dist[s] = 0;
    for (int i = 0; i < n;i++){
        for (auto c : e){
            int u = c.first.first;
            int v = c.first.second;
            int w = c.second;
            if(dist[v] > dist[u] + w){
                dist[v] = dist[u] + w;
            }
        }
    }
}
int main()
{
    //fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n,m;
    cin >> n >> m;

    for (int i = 0; i < m;i++){
        int a, b, c;
        cin >> a >> b >> c;
        e.push_back({{a, b},c});
        e.push_back({{b, a},c});
    }
    int s;
    cin >> s;

    bell(s,n);

    for (int i = 0; i < n;i++){
        cout << dist[i] << " ";
    }

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
