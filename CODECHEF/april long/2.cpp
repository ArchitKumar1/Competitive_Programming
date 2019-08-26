#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;


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
    string a;
    cin >> a;
    char b;
    cin >> b;
    ll ans = 0LL;
    ll total = n * (n + 1LL) / 2LL;
    for (ll i = 0LL; i < n;i++){
        if(a[i] == b){
            continue;
        }
        else{
            ll temp = 0LL;
            ll j = i;
            while (j < n && a[j]!=b){
                temp++;
                j++;
            }
            ans += temp * (temp + 1LL) / 2LL;
            i = j;
        }
    }
    cout << total  - ans << endl;
}

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
