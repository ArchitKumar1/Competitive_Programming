#include<bits/stdc++.h>
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;
typedef long long ll;

const int n = 9;
int grid[n][n];

bool issafe(int r,int c,int val){
	int r1 = r / 3;
	int c1 = c / 3;
	for (int i = 0; i < n;i++) if(grid[i][c] ==  val) return 0;
	for (int j = 0; j < n;j++) if(grid[r][j] ==  val) return 0;
	for (int i = 3 * r1; i < 3 * (r1 + 1); i++){
		for (int j = 3 * c1; j < 3 * (c1 + 1); j++){
			if(grid[i][j] == val)
				return 0;
		}
	}
	return 1;
}

bool next(int &i,int &j){
	for (i = 0; i < n;i++) for (j = 0; j < n;j++) if(grid[i][j] == 0) return 1;
	return 0;
}
bool solve(){
	int r, c;
	if(!next(r, c)) return 1;
	for (int i = 1; i <= n;i++){
		if(issafe(r,c,i)){
			grid[r][c] = i;
			if(solve() == 1) return 1;
			else grid[r][c] = 0;
		}
	}
	return 0;
}
int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	for (int i = 0; i < n;i++){
		for (int j = 0; j < n;j++){
			cin >> grid[i][j];
		}
	}
	if(solve()){
		for (int i = 0; i < n;i++){
			for (int j = 0; j < n;j++){
				cout << grid[i][j] << " ";
			}
			cout << endl;
		}
	}
	else{
		cout << " unsolvable";
	}
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}