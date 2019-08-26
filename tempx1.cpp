#include<bits/stdc++.h>
using namespace std;

const int N = 123456;
int dp1[N], dp2[N];

vector<int> e[N];


struct node{
    int n;
    node(int a){
        
    }
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        for (int j = 0; j < n;j++){
            for (int k = 0; k < n;k++){
                int x, y, z;
                cin >> x >> y >> z;
            }
        }
    }

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}