#include<bits/stdc++.h>
using namespace std;

void solve(){


    string s;
    cin >> s;
    int n = s.length();
    if(n == 1){
        cout << "DPS";
        return;
    }
    int a[128];
    for (int i = 0; i < 128;i++)
        a[i] = 0;
    for (int i = 0;i<n;i++){
        a[s[i]]++;
    }
    
    int cnt = 0;
    if(n%2 == 0 ){
        for (int i = 0;i<128;i++){
            if(a[i]%2 == 1)
                cnt++;
        }
        if(cnt == 2){
            cout << "DPS";
        }else{
            cout << "!DPS";
        }
    }else{
        for (int i = 0;i<128;i++){
            if(a[i]%2 == 1)
                cnt++;
        }
        if(cnt == 3){
            cout << "DPS";
        }else{
            cout << "!DPS";
        }
    }
    cout << endl;

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