#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL);cout.tie(NULL);
using namespace std;




int main() {
	fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	int a[5] = {1, 2, 3, 4, 5};
	for(auto c : a)
		cout << c << " ";

#ifndef ONLINE_JUDGE
	cout << endl << endl << endl << endl;
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}

