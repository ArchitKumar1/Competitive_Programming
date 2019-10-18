#include<bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;
const int N = 10;

vector<int> e[N];
map<pii, set<int>> forbidden;
pii p[N][N];
int d[N][N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n, m, k;
    cin >> n >> m >> k;

    for (int i = 0; i < m ;i++){
        int x, y;
        cin >> x >> y;
        e[x].push_back(y);
        e[y].push_back(x);
    }

    for (int i = 0; i < k;i++){
        int a, b, c;
        cin >> a >> b >> c;
        if(!forbidden.count({a,b})){
            forbidden[{a, b}] = set<int>();
        }
        forbidden[{a, b}].insert(c);
    }
    memset(d, -1, sizeof(d));
    d[0][1] = 0;

    queue<pii> q;
    q.push({0, 1});
    while(not q.empty()){
        int pre = q.front().first;
        int u = q.front().second;
        q.pop();
        for(int v : e[u]){
            if(not forbidden[{pre,u}].count(v) && d[u][v] == -1){
                d[u][v] = d[pre][u] + 1;
                p[u][v] = {pre, u};
                q.push({u,v});
            }
        }
    }
    
    int best = 1;
    for (int i = 1; i < n;i++){
        if(d[i][n] != 1 && (d[best][n] == -1 || d[i][n] < d[best][n])){
            best = i;
        }
    }
    cout << d[best][n] << endl;
    if(d[best][n]!= 1){
        int u = best;
        int v = n;
        vector<int> path;
        while(v!=1){
            path.push_back(v);
            auto pred = p[u][v];
            u = pred.first;
            v = pred.second;
        }
        path.push_back(1);
        reverse(path.begin(),path.end());
        for(int u : path){
            cout << u << " ";
        }
        cout << endl;
    }

   
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}