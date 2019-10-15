#include<bits/stdc++.h>
using namespace std;
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

int main() {

#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int x;
    cin >> x;

    int price[x];
    for (int i = 0; i < x;i++){
        cin >> price[i];
    }
    int n;
    cin >> n;

    vector<int> dp1(n + 1,0);
    vector<int> dp2(n + 1,1);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= i;j++){
            dp1[i] = max(dp1[i], price[j - 1] + dp1[i - j]);
        }
    }

    for (int i = 1; i <= n;i++){
        for (int j = 1; j <= i;j++){
            dp2[i] = max(dp2[i], price[j - 1] * dp2[i - j]);
        }
    }
        cout << dp1[n] << " " << dp2[n];
    return 0;
}