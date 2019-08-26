#include<bits/stdc++.h>
using namespace std;
#define ll long long int

const int N = 1234567;


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> r(n, 0);
        vector<int> c(n, 0);
        bool ok = 1;
        for (int i = 0; i < n;i++){
            for (int j = 0; j < n;j++){
                int x;
                cin >> x;
                if(x == 0) {
                    r[i] = 1;
                    c[j] = 1;
                }
            }
        }
        for (int i = 0;i<n;i++){
            if(r[i] == 0 || c[i] == 0){
                 ok = 0;
                break;
            }
        }
        ok == 1 ? cout << "YES" << endl : cout << "NO" << endl;
    }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}