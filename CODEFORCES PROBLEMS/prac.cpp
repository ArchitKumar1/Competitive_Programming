#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;



int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#endif

	int n,a[100],ans = 0;
	cin >> n;
	for(int i=0;i<n;i++)
		cin >> a[i];
	for(int  i = 0; i < n; i++){
		for(int j = i; j < n ;j++){
			int cnt = 0;
			for(int k=0;k<n;k++){
				(i <= k && k <= j) ? cnt += 1-a[k] : cnt += a[k];
			}
			ans = max(ans, cnt);
		}

	}
	cout << ans;
	return 0;

}
