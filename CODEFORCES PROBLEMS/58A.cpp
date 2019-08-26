#include<bits/stdc++.h>

using namespace std;

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    string a = "hello";
    string b;
    cin >> b;
    int j = 0;
    for (int i = 0; i < b.length();i++){
        if(a[j] == b[i]){
            j++;
        }
        if(j == a.length()){
            break;
        }
        
    }
    j == a.length() ? cout << "YES" << endl: cout << "NO" << endl;
}