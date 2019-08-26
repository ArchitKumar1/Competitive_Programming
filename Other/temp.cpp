#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

int main()
{


	string s1;
	cin>>s1;
	int l=s1.size();

	set<string> set1;
	for(int i=1;i<l;i++){
		for(int j=0;j<=i;j++){
			string s2=s1.substr(j,i);
			set1.insert(s2);
		}
	}
	for(int i=0;i<set1.size();i++){
		cout<<set1[i]<<endl;
	}
	return 0;
}
