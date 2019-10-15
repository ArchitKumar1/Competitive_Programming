#include<bits/stdc++.h>
using namespace std;
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;

map<string, vector<string>> m1;
map<string,int> m2;
int ans = 0;



int dfs(string s){
    int len = 1;
    int m = 0;
    for(auto c : m1[s]){
        if(m2[c] == 0){
            m2[c] == 1;
            m = max(m, dfs(c));
        }
    }
    return len + m;
}
string lower(string s){
    for (int i = 0;i<s.length();i++){
        if(s[i]>=65 && s[i]<=90)
            s[i] += 32;
    }
    return s;
}
int main() {

#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    
    for (int i = 0; i < n;i++){
        string a, b, c;
        cin >> a >> b >> c;
        m1[lower(c)].push_back(lower(a));
        
    }
    cout << dfs("polycarp");
    
    
    return 0;
}