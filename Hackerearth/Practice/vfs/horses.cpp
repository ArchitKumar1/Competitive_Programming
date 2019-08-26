#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const ll N = (ll)1e6 + 50;
const ll Mod = (ll)1e9 + 7;
int ans[N];

void pre(){
    ll x = 1;
    for (ll i = 1; i < (ll)1e6 + 40;i++){
        x *= (i+1);
        x %= Mod;
        ans[i] = x - 1;
    }
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    pre();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        cout << ans[n] << "\n";
    }

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}