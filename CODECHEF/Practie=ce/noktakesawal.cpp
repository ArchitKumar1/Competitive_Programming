#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;
typedef vector<int,int>  v1di;
typedef vector<int> vi;
vector<Pair> v1;

int main()
{
	ll n;
	cin>>n;
	ll arr[n];
	for(ll i=0;i<n;i++) cin>>arr[i];
    map<ll, ll>  vis;
    for (ll i = 0; i < n; ++i)
        vis[arr[i]] = 1;
    ll k = vis.size();
    vis.clear();
    ll ans = 0, right = 0, window = 0;
    for (ll left = 0; left < n; ++left) {
        while (right < n && window < k) {
            ++vis[ arr[right] ];
            if (vis[ arr[right] ] == 1)
                ++window;
            ++right;
        }
        if (window == k)
            ans += (n - right + 1);
        --vis[ arr[left] ];
        if (vis[ arr[left] ] == 0)
                --window;
    }
    cout<<ans<<endl;
    return 0;
}
