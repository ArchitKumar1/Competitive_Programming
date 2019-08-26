#include<bits/stdc++.h>
using namespace std;

string ans;
void solve1(string x){
    if(x.size() == 1){
        ans = x;
        return;
    }
    else{
        int sum = 0;
        for (int i = 0; i < x.length();i++){
            sum += x[i] - '0';
        }
        string y = to_string(sum);
        solve1(y);
    }
    
}
int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    string n;
    int k;
    cin >> n >> k;
    solve1(n);
    string m ="";
    for (int i = 0; i < k;i++)
        m+= ans;
    solve1(m);
    cout << ans;
    return 0;
}
    