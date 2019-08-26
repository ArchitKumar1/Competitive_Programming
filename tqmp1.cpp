#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int ans = 0LL;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    ll t;
    cin >> t;
    while(t--){
        ll n, m;
        cin >> n >> m;
        ll rem[1000];
        ll pos = -1;
        bool ok = 0;
        while(n > 0 && m > 0 && ok == 0){
            pos++;
            if (n < m){
                swap(n, m);
            }
            ll temp = n % m;
            if(temp == 0){
                ok = 1;
            }
            n = n / m;

            if(n!= 1 && ok== 0){
                pos % 2 == 0 ? cout << "A" << endl: cout << "R" << endl;
                ok = 1;
            }
        }
        if(ok == 0)
            pos&1 ? cout << "R" << endl : cout << " A" << endl;
    }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}