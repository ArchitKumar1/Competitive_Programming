#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;


int main()
{
	fastio
	
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	set<vector<int> > s;
	s.insert(vector<int>(5, -1));
	for( auto x = s.begin(); x != s.end();x++){
		for (int i = 0; i < (*x).size();i++){
			cout << (*x)[i] << " ";
		}
	}

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
