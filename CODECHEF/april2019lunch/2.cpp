#include<bits/stdc++.h>
using namespace std;
const int N = 1000000;
int a[N];
int b[N];
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        int ans = 0;

        for (int i = 1; i <=n;i++){
            int x;
            cin >> x;
            a[i] = a[i-1] + x;
        }
        for (int i = 1; i <= n;i++){
            int x;
            cin >> x;
            b[i] = b[i-1] + x;;
        }
        for (int i = 1; i <= n + 1;i++){
            ans = max(ans, a[i - 1] + b[n] - b[i-1]);
        }
        for (int i = 0; i < n  + 1;i++){
            a[i] = 0;
            b[i] = 0;
        }
            cout << ans << endl;
    }
}
