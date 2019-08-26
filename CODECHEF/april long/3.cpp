#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

map<pair<ll,ll>,ll > m1,m2;
ll ans = 0LL;
ll n, m,k;

ll dx[4LL] = {0LL, -1LL, 0LL, 1LL};
ll dy[4] = {1LL, 0LL, -1LL, 0LL};

void dfs(ll i, ll j){

    if(i<0LL || j<0LL || i>n || j>m){
        return;
    } 
    if(m1[{i,j}] && !m2[make_pair(i,j)]){
        m2[make_pair(i, j)]++;
        for (int k = 0LL; k < 4LL;k++){
            if(!m1[{i+dx[k],j+dy[k]}]){
                ans++;
            }
            else{
                dfs(i + dx[k], j + dy[k]);
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

TC{
    m1.clear();
    m2.clear();
    cin >> n >> m;
    cin >> k;
    ans = 0LL;
    for (ll i = 0LL; i < k;i++){
        ll r, c;
        cin >> r >> c;
        m1[make_pair(r,c)]++;
    }

    for(auto it : m1){
        ll a = it.first.first;
        ll b = it.first.second;
        if(!m2[{a,b}]){
            dfs(a, b);
        }
    }
    cout << ans << endl;

}
    

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
