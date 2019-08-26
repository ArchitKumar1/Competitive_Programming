#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second


void solve(){
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    int gcd = arr[0];
    for(int i=1;i<n;i++){
        gcd = __gcd(gcd, arr[i]);
        
    }
    if(gcd == 1){
        cout << "Fake Offer!" << endl;
    }else{
        cout << 1 + *max_element(arr, arr + n) << endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    solve();
    return 0;    
            
}