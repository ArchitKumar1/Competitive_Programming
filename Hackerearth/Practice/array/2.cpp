#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL),cout.tie(NULL);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;



int main(){
#ifndef ONLINE_JUDGE 
    fastio
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    int q;
    cin >> n >> q;
    int a[n];
    int pos[n];
    fill(a, a + n, 0);
    fill(pos, pos + n, 0);
    for (int i = 0; i < n;i++){
        int x;
        cin >> a[i];
    }
    for (int i = 0; i < q;i++){
        int x;
        cin >> x;
        if(x){
            int y;
            cin >> y;
            pos[--y] ^= 1;
        }
        else{
            int l, r;
            cin >> l >> r;
            int ans = a[--r] ^ pos[r];
            ans == 0 ? cout << "EVEN" << "\n" : cout << "ODD" << "\n";
        }
    }

#ifndef ONLINE_JUDGE
		cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}