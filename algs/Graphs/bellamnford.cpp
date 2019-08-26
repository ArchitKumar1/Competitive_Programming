
#include <bits/stdc++.h>
using namespace std;
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vii;
#define INF 0x3f3f3f3f


vector<pair<int, pair<int, int>>> e;
vector<int> dist;

void bellman(int n,int s){
    dist.assign(n, INF);
    dist[s] = 0;

    for (int k = 0; k < n;k++){
        for (auto c : e){
            int w = c.first;
            int i = c.second.first;
            int j = c.second.second;

            if (dist[j] > dist[i] + w){
                dist[j] = dist[i] + w;
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

    for (int i = 0; i < n;i++){
        int x, y, z;
        cin >> x >> y >> z;
        e.push_back({z, {x, y}});
        e.push_back({z, {y, x}});

    }

    int s;
    cin >> s;

    bellman(n, s);

    for (int i = 0; i < n;i++){

        cout << dist[i] << " ";
    }
        return 0;
}