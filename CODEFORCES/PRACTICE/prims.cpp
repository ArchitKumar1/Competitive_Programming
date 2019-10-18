#include<bits/stdc++.h>

using namespace std;

const int N = 10000;

struct edge{
    int u, v, w;
    bool operator<(edge const& other){
        return w < other.w;
    }
};

vector<edge> edges,result;
int id[N];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n,m;
    cin >> n >> m;
    edge temp;
    for (int i = 0; i < m;i++){
        int a, b, c;
        cin >> temp.u >> temp.v >> temp.w;
        edges.push_back(temp);
        swap(temp.v, temp.u);
        edges.push_back(temp);
    }
    for (int i = 0; i < n; i++){
        id[i] = i;
    }

    sort(edges.begin(), edges.end());
    int cost = 0;
    for(edge e : edges){
        if(id[e.u] != id[e.v]){
            cost += e.w;
            result.push_back(e);
            for (int i = 0; i < n;i++){
                if(id[i] == id[e.u]){
                    id[i] = id[e.v];
                }
            }
        }
    }
    result.resize(n-1);
    for(edge e : result){
        cout << e.u << " " << e.v << " " << e.w << endl;
    }
    cout << cost << endl;

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}