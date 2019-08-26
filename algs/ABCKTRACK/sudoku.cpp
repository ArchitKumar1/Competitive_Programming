#include<bits/stdc++.h>
using namespace std;

const int N = 9;
const int NN = pow(N, 0.5);
int grid[N][N];

bool safe(int r,int c,int num){
    for (int i = 0; i < N;i++) if(grid[i][c] == num) return 0;
    for (int j = 0; j < N;j++) if(grid[r][j] == num) return 0;
    int r1 = r / NN;
    int c1 = c / NN;
    for (int i = NN * r1; i < NN * (r1 + 1);i++){
        for (int j = NN * c1; j < NN * (c1 + 1);j++){
            if(grid[i][j] == num) return 0;
        }
    }
    return 1;
}
bool next(int &r,int &c){
    for (r = 0; r < N;r++){
        for (c = 0; c < N;c++){
            if(grid[r][c] == 0)
                return 1;
        }
    }
    return 0;
}

bool solve(){
    int r, c;
    if(!next(r,c)){
        return 1;
    }
    for (int v = 1; v <= N;v++){
        if(safe(r,c,v)){
            grid[r][c] = v;
            if(solve() == 1){
                return 1;
            }else{
                grid[r][c] = 0;
            }
        }
    }
    return 0;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    
    solve();
    cout.width(3);
    for (int i = 0; i < N;i++){
        for (int j = 0; j < N;j++){
            cout << left << setw(3) << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
    