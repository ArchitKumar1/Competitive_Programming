#include<bits/stdc++.h>
#define LINF 100000000000
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long int ll;
using namespace std;
int n,m,u,v,x,b;
vector< pair<int,int> > graph[100009];
ll *distances;
vector<bool> visited;
void djikstra(int start) {
    distances = new ll[n+1];
    visited.assign(n+1, false);
    fill(distances, distances+n+1, (ll)LINF);
    distances[0] = 0;
    multiset< pair<ll,int> > s;
    s.insert(make_pair(0, start));
    while(!s.empty()) {
        pair<ll, int> p = *s.begin();
        s.erase(s.begin());
        int x = p.second;
        if(visited[x]) continue;
        visited[x] = true;
        rep(i,graph[x].size()) {
            int e = graph[x][i].first, w = graph[x][i].second;
            if(distances[x] + w < distances[e]) {
                distances[e] = distances[x] + w;
                s.insert(make_pair(distances[e], e));
            }
        }
    }
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    scanf("%d %d", &n, &m);
    
    rep(i,m) {
        scanf("%d %d %d", &u,&v,&x);
        graph[u].push_back(make_pair(v,x));
        graph[v].push_back(make_pair(u,x));
    }
    scanf("%d", &b);
    while(b--) {
        scanf("%d", &x);
        graph[0].push_back(make_pair(x, 0));
        graph[x].push_back(make_pair(0, 0));
    }
    djikstra(0);
    for(int i=1;i<=n;i++) printf("%lld\n", distances[i]);
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}