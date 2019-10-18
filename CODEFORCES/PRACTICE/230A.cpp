#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;

const int maxn = 1010;
vector<pair<int,int>> dra;
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif

	int s,n;
	cin >>s >>n;
	forn(i,n){
		int x,y;
		cin >> x >> y;
		dra.push_back(make_pair(x,y));
	}
	sort(dra.begin(),dra.end());
	int ans = 1;
	for(int i=0;i<n;i++){
		if(s > dra[i].first){
			s += dra[i].second;
		}
		else{
			ans = 0;
			break;
		}
	}
	if(ans == 1)
		cout << "YES" ;
	else
		cout << "NO" ;



	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif

	return 0;

}
