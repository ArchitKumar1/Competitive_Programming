#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL),cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;



int main(){
#ifndef ONLINE_JUDGE 
    fastio
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;

    map<int, int> m1;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        m1[x]++;
    }
    priority_queue<pair<int, int>> p1;
    for(auto it: m1){
        p1.push(make_pair(it.second, it.first));
    }
    pair<int, int> x = p1.top();
    p1.pop();
    int ans = x.second;
    while(!p1.empty() && p1.top().first == x.first){
        ans = p1.top().second;
        p1.pop();
    }
    cout << ans;

#ifndef ONLINE_JUDGE
		cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}