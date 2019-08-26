#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int star[11][105][105];
const int N = 105;
int main()
{
	//fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	fastio
	mset(star,0);
	int n,q,c;
	cin >> n >> q >> c;
	for(int i = 1; i <= n; i++){
		int x, y, s;
		cin >> x >> y >> s;
		++star[s][x][y];
	}
	for(int k=0;k<=c;k++){
		for(int i=1;i<N;i++){
			for(int j=1;j<N;j++){
				star[k][i][j] += (star[k][i - 1][j] + star[k][i][j-1]  - star[k][i-1][j-1]);
			}
		}
	}
	while(q--){
		int t,x1,y1,x2,y2,cnt;
		int ans = 0;
		cin >> t >> x1 >> y1 >> x2 >> y2;
		for(int i =0;i<=c;i++){
			cnt = (star[i][x2][y2] - star[i][x1-1][y2] - star[i][x2][y1-1] + star[i][x1-1][y1-1]);
			ans += cnt*((i+t)%(c+1));
 		}
 		cout << ans <<endl;
	}

#ifndef ONLINE_JUDGE
	cout << endl << endl <<endl <<endl;
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
