#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
using namespace std;

int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#endif

	int arrs[1000] = {0};
	int arrt[1000] = {0};

	string s,t;
	cin >> s >> t;

	if(s.length() != t.length()){cout << "No" <<endl, exit(0);}
	int n = s.length();

	string vow = "aeiou";
	for(int i=0;i<n;i++) for(int j=0;j<5;j++) if(s[i] == vow[j]) arrs[i] = 1;
	for(int i=0;i<n;i++) for(int j=0;j<5;j++) if(t[i] == vow[j]) arrt[i] = 1;
	for(int i=0;i<n;i++){
		if(arrs[i] != arrt[i]){
			cout << "No" <<endl;
			exit(0);
		}
	}
	cout << "Yes" <<endl;
	return 0;

}
