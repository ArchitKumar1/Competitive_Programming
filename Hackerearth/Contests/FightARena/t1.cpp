#pragma GCC optimize ("O3")
#pragma comment(linker, "/stack:200000000")
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long int
void solve(){

    int n;
    cin >> n;
    int a[n];
    ll sum = 0;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        sum += x;
    }
    double ans = (double)sum / n;
    if(ans -int(ans) == 0){
        cout << int(ans) + 1 << endl;
    }else{
        cout << floor(ans) << endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    // int t;
    // cin >> t;
    // while(t--)
        solve();
    return 0;
}