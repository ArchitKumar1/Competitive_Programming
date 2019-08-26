#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

bool ok = 0;
int c = 0;
vector<int> f;
void dfs(int a,int b){
    if(a > b) return;
    f.push_back(a);
    if(a == b){
        cout << "YES" << endl <<  f.size() << endl;
        for(auto z : f){
            cout << z << " ";
        }
        exit(0);
    }
    dfs(2 * a, b);
    dfs(10*a + 1, b);
    f.pop_back();
}
int main()
{
    //fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    ll a,b;
    cin >> a >> b;
    dfs(a, b);
    cout << "NO" << endl;
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
