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

    int n;
    cin >> n;
    int c;
    cin >> c;
    int p[n], w[n];
    for (int i = 0; i < n;i++){
        cin >> p[i] >> w[i];
    }

    int dp[n+1][c+1];
    memset(dp, 0, sizeof(dp));

    for (int i = 1; i <=n;i++){
        for (int j = 1; j <= c;j++){
            if(j - w[i-1] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i-1]] + p[i-1]);
            else 
                dp[i][j] = dp[i - 1][j];
        }
    }
    
    for (int i = 0; i <=n;i++){
        for (int j = 0; j <= c;j++){
            cout << dp[i][j] << " ";
        }
        cout << endl;
    }
        return 0;

}