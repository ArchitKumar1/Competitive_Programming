#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define mset(a,v) memset(a,v,sizeof(a));
using namespace std;

const int maxn = 1100;

int a[maxn][maxn];
int b1[maxn][maxn],b2[maxn][maxn],b3[maxn][maxn],b4[maxn][maxn];

int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#endif
	int n, m;
	cin >> n >> m;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)
			cin >> a[i][j];
	}
	mset(b1,0);
	mset(b2,0);
	mset(b3,0);
	mset(b4,0);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			b1[i][j] = max(b1[i][j-1],b1[i-1][j]) + a[i][j];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			b2[i][j] = max(b2[i][j+1],b2[i+1][j]) + a[i][j];
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			b3[i][j] = max(b3[i][j-1],b3[i+1][j]) + a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			b4[i][j] = max(b4[i][j+1],b4[i-1][j]) + a[i][j];
		}
	}
	int ans = 0;
	for(int i=2;i<n;i++){
		for(int j=2;j<m;j++){
			ans = max(ans, b1[i-1][j] + b2[i+1][j] + b3[i][j-1] + b4[i][j+1]);
			ans = max(ans, b1[i][j-1] + b2[i][j+1] + b3[i+1][j] + b4[i-1][j]);
		}
	}
	cout << ans << endl;
	return 0;

}
