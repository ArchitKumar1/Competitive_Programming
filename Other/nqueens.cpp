#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;


const int N = 100;
int grid[N][N];
int n;
bool issafe(int r,int c){
	for (int i = r ,j = c ; i >=0 && j>=0;i--,j--){
		if(grid[i][j] == 1)
			return 0;
	}
	for (int i = r ,j = c ; i >=0 && j<n;i--,j++){
		if(grid[i][j] == 1)
			return 0;
	}
	for (int i = 0; i <=r;i++){
		if(grid[i][c] == 1)
			return 0;
	}
	return 1;
}
int total = 0;
void nqueen(int row){
	if(row == n)
		total+=1;
	for (int j = 0; j < n;j++){
		if(issafe(row,j)){
			grid[row][j] = 1;
			nqueen(row + 1);
			grid[row][j] = 0;
		}
	}
}
int main()
{
	fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	cin >> n;
	nqueen(0);
	cout << total;
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
