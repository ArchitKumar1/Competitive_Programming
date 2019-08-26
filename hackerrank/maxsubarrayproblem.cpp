#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n];
    int ma = INT_MIN;
    for (int i = 0; i < n;i++){
        cin >> a[i];
        ma = max(ma, a[i]);
    }
    if(ma<0){
        cout << ma << " " << ma << endl;
        return;
    }
    int m1 = 0;
    int m2 = 0;
    for (int i = 0; i < n;i++){
        m2 += a[i];
        if(m2 < 0) m2 = 0;
        m1 = max(m1, m2);
    }
    cout << m1 << " ";

    m1 = 0;
    for (int i = 0; i < n;i++){
        if(a[i]>0){
            m1 += a[i];
        }
    }
    cout << m1 << endl;
}
int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}
    