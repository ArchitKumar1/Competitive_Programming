#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;


int main()
{
    //fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    set<int> s;

    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        s.insert(x);
    }
    if(s.size() == 1){
        cout << "0" << endl;
        exit(0);
    }
    int a, b;

    auto it1 = max_element(s.begin(), s.end());
    a = *it1;
    s.erase(it1);
    auto it2 = max_element(s.begin(), s.end());
    b = *it2;

    cout << b << endl;

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
