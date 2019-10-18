#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int memo[105][105][15][15];
int k1, k2;
int MOD = 1000 * 1000 * 1000;
int calc(int n1,int n2,int x1,int x2){
    if(n1== 0 && n2 == 0){
        return 1;
    }
    int x = memo[n1][n2][x1][x2];
    if(x !=-1){
        return x;
    }
    int ret = 0;
    if(n1 > 0 && x1 < k1){
        ret += calc(n1 - 1, n2, x1 + 1, 0);
    }
    if(n2 > 0 && x2 < k2){
        ret += calc(n1, n2 - 1, 0, x2 + 1);
    }
    ret %= MOD;
    return ret;
}

int main(){

#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    memset(memo, -1, sizeof(memo));
    int n1, n2;
    cin >> n1 >> n2 >> k1 >> k2;
    cout << calc(n1,n2,0,0);

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}