#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<ll> vll;
typedef vector<vll> vvll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n,m;
    cin >> n >> m;
    int a[m];
    for (int i = 0; i < m;i++){
        cin >> a[i];
    }
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n;i++){
        dp[i] = 0;
        for (int j = 0; j < min(i,m) ;j++){
            dp[i] = max(dp[i], dp[i - j - 1] + a[j]);
        }
    }
    for (int i = 0; i <= n;i++){
        cout << dp[i] << " ";
    }
    cout << endl;
    cout << dp[n] << endl;
    return 0;

}