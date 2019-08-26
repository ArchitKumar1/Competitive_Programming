#pragma GCC optimize ("O3")
#pragma comment(linker, "/stack:200000000")

#include<bits/stdc++.h>
using namespace std;
void solve(){

    int n;
    cin >> n;
    long long int ans = 0;
    for (int i = 3; i <=n;i++){
        ans += (i - 1) * (i - 2);
    }
    cout << ans << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    solve();return 0;
}