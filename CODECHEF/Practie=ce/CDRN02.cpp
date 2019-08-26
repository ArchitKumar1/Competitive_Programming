#include<bits/stdc++.h>
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;


int main()
{
    fastio
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
TC{

    int n, m, p, q;
    cin >> n >> m >> p >> q;

    if(p>n && q > n){
        cout << "1" << endl;
    }else if(p>n){
        cout << m - q + 1 << endl;
    }
    else if(m<q){
        cout << n - p + 1 << endl;
    }else{
        cout << (n - p + 1) * (m - q + 1) << endl;
    }
}
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}
