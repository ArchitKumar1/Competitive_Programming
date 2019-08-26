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

const int N = (int)1e5;

struct ed{
	int w,i,j;
};
vector<int> mark(N,0);
vector<ed> ans;

auto compare = [](ed a, ed b) {return a.w > b.w;};



int main(){
    fastio    
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;
	cin >> n;
	ed temp;
	for (int i = 0; i < n;i++){
		int x, y, z;
		cin >> temp.w >> temp.i >> temp.j;
		pq.push(temp);
		swap(temp.i, temp.j);
		pq.push(temp);
	}
	kru(n);
	for (auto c : ans){
		cout << c.i << " " << c.j << " " << c.w << endl;
	}
#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}