#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1234567;

vector<int> e[N];
vector<int> vis,dis;


int bfs(int s,int x,int n){
    queue<int> l;
    vis.assign(n+1, 0);
    dis.assign(n+1, 0);
    int cnt = 0;
    l.push(s);
    dis[s] = 0;
    vis[s] = 1;
    while(!l.empty()){
        int t = l.front();
        l.pop();
        for(auto c : e[t]){
            if(!vis[c]){
                vis[c] = 1;
                dis[c] = dis[t] + 1;
                if(dis[c] == x){
                    ++cnt;
                }
                l.push(c);
            }
        }
    }
    return cnt;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    int m;
    cin >> n >> m;

    for (int i = 0; i < m;i++){
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int q;
    cin >> q;
    while(q--){
        int s, t;
        cin >> s >> t;
        cout << bfs(s, t, n) << endl;
    }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}