#include<bits/stdc++.h>
using namespace std;
#define ll long long int

ll cost = 0LL;
map<string, pair<string, int>>m1;
map<string, int> m2,m3;
set<string> ss;

void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n - 1;i++){
        string a, b;
        int c;
        cin >> a >> b >> c;
        cost += c;
        m2[b] = 1;
        //cout << c << endl;
        m3[a] = 1;
        m1[a] = {b, c};
        ss.insert(a), ss.insert(b);
    }
    string start,end;
    for(string s : ss){
        if(!m2[s]){
            start = s;
            break;
        }
    }
    for(string s : ss){
        if(!m3[s]){
            end = s;
            break;
        }
    }
    
    for (string s = start; s != end;s = m1[s].first){
        cout << s << " " << m1[s].first << " "<<m1[s].second << endl;
    }
    cout << cost << endl;
    cost = 0;
    m1.clear();
    m2.clear();
    m3.clear();
    ss.clear();
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}