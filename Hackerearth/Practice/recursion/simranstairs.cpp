#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n;i++){
        dp[i] = 0;
        for (int j = 1; j <=3;j++){
            if(i >= j){
                dp[i] += dp[i-j] +1;
            }
        }
    }
    cout << dp[n -1] << endl;
        return 0;
}
    