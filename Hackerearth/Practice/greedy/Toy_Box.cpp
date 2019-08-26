#include<bits/stdc++.h>
using namespace std;


void solve(){
    int n, m;
    cin >> n >> m;
    pair<int, int> p[n];
    for (int i = 0; i < n;i++){
        cin >> p[i].first >> p[i].second;
    }
    sort(p,p+n);
    reverse(p, p + n);
    int sum = 0;
    vector<int> done(n+1, 0);
    for (int i = 0; i < n;i++){
        if(!done[p[i].second]){
            sum += p[i].first;
            done[p[i].second] = 1;
        }
    }
    cout << sum << endl;
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    // int t;
    // cin >> t;
    //while(t--)
        solve();
    return 0;
}
    