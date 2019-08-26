#include<bits/stdc++.h>
using namespace std;
#define ll long long int


int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        ll n, m;
        ll pos = -1;
        cin >> n >> m;
        bool ok1 = 0;
        bool ok2 = 0;
        while(ok2 == 0){
            pos++;
            if(n < m) swap(n,m);
            ll q = n / m;
            ll rem = n % m;
            n = rem;
            if(q!= 1){
                pos % 2 == 0 ? cout << "Ari" << endl : cout << "Rich" << endl;
                ok2 = 1;
                ok1 = 1;
            }
            if(rem == 0){
                ok2 = 1;
            }
        }
        if(ok1 == 0){
            pos % 2 == 0 ? cout << "Ari" << endl : cout << "Rich" << endl;
        }
    }

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}