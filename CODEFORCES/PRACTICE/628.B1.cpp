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

    string s;
    cin >> s;

    int n = s.length();
    ll a = 0LL, b = 0LL;
    for (int i = 0; i < n ;i++){
        if(i<n-1){
            if(stoi(s.substr(i, 2)) %4 == 0 ){
                a += (i + 1);
            }
        }
        if((s[i] - '0') == 0 || (s[i] - '0')  == 4 || (s[i] - '0') == 8){
            b++;
        }
    }
    cout << a +b;
#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}