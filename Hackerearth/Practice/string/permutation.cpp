#pragma GCC optimize ("O3")
#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define fi first
#define se second
vector<string> ans;
void perm(string a,int k){
    if(k == a.length() -1){
        ans.push_back(a);
        return;
    }
    else{
        for (int i = k; i < a.length();i++){
            swap(a[k], a[i]);
            perm(a, k + 1);
            swap(a[k], a[i]);
        }
    }
}
void solve(){
    string a;
    cin >> a;
    sort(a.begin(), a.end());
    int k = a.length();
    perm(a, 0);
    sort(ans.begin(), ans.end());
    for(string x : ans){
        cout << x << " ";
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    solve();
    return 0;    
            
}