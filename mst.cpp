
#include <bits/stdc++.h>
using namespace std;
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vpii;
#define INF 0x3f3f3f3f

const int N = 1000;

vector<pair<int, int>> e[N];
vector<int> dist;



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
        e[x].push_back({y,z});
        e[y].push_back({x,z});

    }


    return 0;
}