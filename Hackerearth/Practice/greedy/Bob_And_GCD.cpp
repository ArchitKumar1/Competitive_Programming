#include<bits/stdc++.h>
using namespace std;

const int N = 123456;

void solve(){
    int k;
    cin >> k;
    int n;
    cin >> n;
    
    long long int ans = 0LL;
    for (int i = 0; i < n;i++) {
        int x;
        cin >> x;
        ans += min(x % k, k - x % k);
    }
    cout << ans << endl;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
    