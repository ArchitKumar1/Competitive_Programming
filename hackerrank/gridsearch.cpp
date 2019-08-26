#include<bits/stdc++.h>
using namespace std;

const int N = 1050;
string g[N];
string p[N];
int r1, r2, c1, c2;
void solve(){
    cin >> r1 >> c1;
    for (int i = 0; i < r1;i++){
        cin >> g[i];
    }
    cin >> r2 >> c2;
    for (int i = 0; i < r2;i++){
        cin >> p[i];
    }

    bool ok = 0;
    for (int i = 0; i < r1 - r2 + 1;i++){
        for(int j = 0; j<c1 -c2 +1;j++){
            bool ok2 = 1;
            for (int k = 0; k < r2;k++){
                for (int l = 0; l < c2;l++){
                    if(g[i+k][j+l] != p[k][l] ){
                        k = r2, l = c2;
                        ok2 = 0;
                    }
                }
            }
            if(ok2 == 1){
                ok = 1;
                break;
            }
        }
    }
    cout << (ok == 1 ? "YES" : "NO") << endl;
    
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}