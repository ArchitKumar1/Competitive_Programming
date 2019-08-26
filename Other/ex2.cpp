#include<bits/stdc++.h>
#include <string>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

 
using namespace std;
const int N = 600;

int ver[N][N];
int hor[N][N];
string dom[N];

int main()
{
	fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int h,w;
    cin >> h  >> w;
    for(int i=0;i<h;i++){
        cin >> dom[i];
    }

    for(int i=0;i<=h;i++){
        for(int j=0;j<=w;j++){
            if(i== 0 || j == 0){
                ver[i][j] = 0;
            }
            else{ 
                ver[i][j] = ver[i-1][j] + ver[i][j-1] - ver[i-1][j-1];
                if(i < h && dom[i-1][j-1] == '.' && dom[i][j-1] == '.')
                    ver[i][j]++;
            }
            if(i== 0 || j == 0){
                hor[i][j] = 0;
            }
            else{ 
                hor[i][j] = hor[i-1][j] + hor[i][j-1] - hor[i-1][j-1];
                if(j < w && dom[i-1][j-1] == '.' && dom[i-1][j] == '.')
                    hor[i][j]++;
            }
        }
        
    }
    int q;
    cin >> q;
    while(q--){
        int r1,c1,r2,c2;
        cin >> r1 >> c1 >> r2 >> c2;
        int ans = 0;
        ans += ver[r2-1][c2] - ver[r2-1][c1-1] - ver[r1-1][c2] + ver[r1-1][c1-1]; 
        ans += hor[r2][c2-1] - hor[r1-1][c2-1] - hor[r2][c1-1] + hor[r1-1][c1-1];
        cout << ans << endl; 
    }
 

#ifndef ONLINE_JUDGE
	cout << endl << endl <<endl <<endl;
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
