#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
#define ll long long int

vector<vector<pair<ll,ll>>> e;
ll sum, total, temp;

void dfs(ll s = 1LL,ll par = 0LL){
    for(auto c : e[s]){
        if(c.first == par ) continue;
        temp += c.second;
        total = max(total, temp);
        dfs(c.first,s);
        temp -= c.second;
    }
}
int main()
{
    fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

TC{
    ll n;
    cin >> n;
    e.resize(n+2);
    temp = 0LL, total = 0LL,sum=0LL;
    for(ll i=1LL;i<n;i++){
        ll x,y,z;
        cin >> x >> y >> z;
        e[x].push_back({y, z});
        e[y].push_back({x, z});
        sum += 2LL*z;

    }
    dfs();
    e.clear();
    cout << sum - total << endl;
}

    
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms.";
#endif
}
