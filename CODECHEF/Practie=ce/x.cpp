#include<bits/stdc++.h>
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++) 
        cin >> a[i];
    bool ok = 1;
    int cur = a[0];
    for (int i = 0; i < n ;i++){
        if(cur == 0) ok = 0;
        cur = max(cur - 1, a[i] );
    }
    ok ==  1 ? cout << "Possible" : cout << "Impossible";

#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}
