#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;



int main(){
    fastio    
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    int m = t;
    while(t--)
    {
        string s;
        cin >> s;

        string ans;

        for (auto c : s)
        {
            (c == 'S') ? ans += 'E' : ans += 'S';
        }
        cout << "Case #" << m - t + 1 << ": " << ans << endl;
}   
   
#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}