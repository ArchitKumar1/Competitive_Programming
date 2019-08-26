#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
using namespace std;

const int n = 9;
int grid[n][n];
bool issafe(int r,int c,int val){
	int r1 = r / 3;
	int c1 = c / 3;
	for (int i = 0, j = 0; i < n && j < n; i++,j++){
		if(grid[i][c] == val) return 0;
		if(grid[r][j] == val) return 0;
	}
	for (int i = 3 * r1; i < 3 * (r1 + 1); i++){
		for (int j = 3 * c1; j < 3 * (c1 + 1); j++){
			if(grid[i][j] == val)
				return 0;
		}
	}
	return 1;
}

bool find(int &i,int &j){
	for (i = 0; i < n;i++){
		for (j = 0; j < n;j++){
			if(grid[i][j] == 0)
				return 1;
		}
	}
	return 0;
}
bool sudoku(){

	int r, c;
	if(!find(r,c))
		return 1;
	for (int k = 1; k <= n;k++){
		if(issafe(r,c,k)){
			grid[r][c] = k;
			if(sudoku() == 1)
				return 1;
			else
				grid[r][c] = 0;
		}
	}
	return 0;
}
int main()
{
	fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	for (int i = 0; i < n;i++){
		for (int j = 0; j < n;j++){
			cin >> grid[i][j];
		}
	}
	int c = sudoku();
	for (int i = 0; i < n;i++){
		for (int j = 0; j < n;j++){
			cout << grid[i][j]<< " ";
		}
		cout << endl;
	}


#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
// 3 0 6 5 0 8 4 0 0
// 5 2 0 0 0 0 0 0 0
// 0 8 7 0 0 0 0 3 1
// 0 0 3 0 1 0 0 8 0
// 9 0 0 8 6 3 0 0 5 
// 0 5 0 0 9 0 6 0 0
// 1 3 0 0 0 0 2 5 0
// 0 0 0 0 0 0 0 7 4
// 0 0 5 2 0 6 3 0 0