#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;


int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	TC{

	int n;
	cin >> n;
	int a[n];
	forn(i,n)
		cin >> a[i];
	int gmax = 0;
	int lmax = 0;
	forn(i,n){
		lmax+= a[i];
		if(lmax<0) lmax = 0;
		gmax = max (gmax,lmax);
	}
	cout << gmax << endl;

	}

	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif

	return 0;

}
