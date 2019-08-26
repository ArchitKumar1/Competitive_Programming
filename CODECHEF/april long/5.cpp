#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define ll long long
using namespace std;

int ans = 0;
void expand(string str, int low, int high, vector<string> &set)
{
	while (low >= 0 && high < str.length() && str[low] == str[high]){
		set.push_back(str.substr(low, high - low + 1));
		low--, high++;
	}
}

void allPalindromicSubstrings(string str)
{

	vector<string> set;
	for (int i = 0; i < str.length(); i++)
	{
		expand(str, i, i, set);
		expand(str, i, i + 1, set);
	}
	for (auto i : set){
		cout << i << endl;
		if(i.length() == 1){
			continue;
		}
		else{
			ans += i.length() - 1;
			ans += i.length() / 2;
		}
	}
}

int main()
{
    fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string str;
	cin >> str;

	allPalindromicSubstrings(str);
	cout << ans << endl;

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
