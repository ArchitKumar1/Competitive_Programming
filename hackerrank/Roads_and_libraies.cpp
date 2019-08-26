#include<bits/stdc++.h>
using namespace std;

const int N = 123456;
int par[N], size[N];
inline void make(int v){
    par[v] = v;
    size[v] = 1;
}
int find(int v){
    if( v == par[v]) return v;
    else return par[v] = find(par[v]);
}
void merge(int a,int b){
    
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i <= n;i++){
        dp[i] = 0;
        for (int j = 1; j <=3;j++){
            if(i >= j){
                dp[i] += dp[i-j] +1;
            }
        }
    }
    cout << dp[n -1] << endl;
        return 0;
}
    