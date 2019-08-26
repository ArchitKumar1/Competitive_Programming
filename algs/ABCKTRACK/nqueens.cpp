#include<bits/stdc++.h>
using namespace std;
const int N = 100;
int grid[N][N];

int n;
void gp(){
    for(int i=0;i<n;i++){
        for (int j = 0; j<n;j++){
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool check(int r,int j){
    for(int i=0;i<r;i++)if(grid[i][j])return 0;
    int x = r, y = j;
    while(--x>=0 && --y>=0) if(grid[x][y])return 0;
    x = r, y = j;
    while(--x>=0 && ++y<=n-1) if(grid[x][y]) return 0;
    return 1;
}
void solve2(int r){
    if(r == n) {gp();return;}
    for (int j = 0; j < n;j++){
        if(check(r,j)){
            grid[r][j] = 1;
            solve2(r + 1);
            grid[r][j] = 0;
        }
    }
}
bool solve(int r){
    if(r == n) {gp(); return 1;}
    for (int j = 0; j < n;j++){
        if(check(r,j)){
            grid[r][j] = 1;
            if(solve(r + 1)) return 1;
            else grid[r][j] = 0;
        }
    }
    return 0;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    cin >> n;
    if(!solve(0)) cout << "Not possible";
    return 0;
}
    