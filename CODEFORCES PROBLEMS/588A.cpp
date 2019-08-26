#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;

const int maxn = 110000;

int a[maxn],b[maxn];

int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int n;
	cin >> n;

	forn(i,n){
		int x,y;
		cin >> x >> y;
		a[i] = x;
		b[i] = y;
	}
	int curr = b[0];
	int total  = 0;
	for(int i=0;i<n;i++){
		curr = min(curr,b[i]);
		total += curr* a[i];
	}

	cout << total  <<endl;
	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif

	return 0;

}
