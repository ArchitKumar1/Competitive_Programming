#include<bits/stdc++.h>
using namespace std;



void solve(){
    int n;
    cin >> n;
    int k;
    cin >> k;
    vector<int> arr(n);
    map<int, int> m1;
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
        m1[arr[i]] = i;
    }
    vector<int> brr(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    for (int i = 0; i < n; i++){
        if(k == 0) break;
        else if(arr[i] == brr[i]) continue;
        else {
            int i1 = i;
            int i2 = m1[brr[i]];
             swap(arr[i], arr[m1[brr[i]]]);
             m1[brr[i]] = i1;
             m1[arr[i]] = i2;
             k--;
        }
    }
    for(int a : arr){
        cout << a << " ";
        
    }
    cout << endl;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int t;
    cin >> t;
    while(t--)
        solve();
    return 0;
}
    