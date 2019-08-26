#include <bits/stdc++.h>
using namespace std;

#define TC ll T; cin >> T; while (--T >= 0)
//#define DEBUG

#define ll long long
const ll mod = 1e9+7;

ll myPow(ll b, ll e, ll m = mod) {
    ll res = 1;
    while (e) {
        if (e&1) {
            res = res*b%m;
        }
        b = b*b%m;
        e >>= 1;
    }
    return res;
}

ll gpSum(ll r, ll n, ll m = mod) {

    
    if (n == 0) {
        return 1;
    } else {
        ll even_sum = gpSum(r*r%m, n/2, m);
        ll odd_sum = r*even_sum%m;
        if (n%2 == 0) {
            odd_sum = (odd_sum + (m - myPow(r, n+1, m)))%m;
        }
        return (even_sum+odd_sum)%m;
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    TC {
        ll n, m;
        cin >> n >> m;
        ll ans = 0;
        for (int i = 1; i <= min(n, m-1); ++i) {
            ll a = myPow(i, i, m), b = myPow(i, m, m);
            ll k = (n-i)/m;
            ans = (ans + a*gpSum(b, k, m)%m)%m;
        }
        cout << ans << '\n';
        #ifdef DEBUG
        ll brute_ans = 0;
        for (int i = 1; i <= n; ++i) {
            brute_ans = (brute_ans + myPow(i, i, m))%m;
        }
        cout << "BRUTE: " << brute_ans << '\n';
        #endif //DEBUG
    }
    
    return 0;
}
