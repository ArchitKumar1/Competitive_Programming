#include<bits/stdc++.h>
using namespace std;
#define ll long long int

typedef vector<pair<int, int>> vpii;

bool cmp1(const pair<int,int> &a,const pair<int,int> &b){
    return a.first < b.first;
}
bool cmp2(const pair<int,int> &a,const pair<int,int> &b){
    return a.second < b.second;
}

void solve(){
    int n;
    cin >> n;
    while(n--){
        int x, y;
        cin >> x >> y;
        
    }
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    cout.precision(10);
    cout << fixed;
    while(t--){
        solve();
    }
    
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}