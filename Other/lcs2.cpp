#include<bits/stdc++.h>
using namespace std;
#define TC int t;  cin >> t; while(t--)
#define ll long long
#define pb push_back

struct p{
	int a,b,c,d;
};
int main(){

	TC{
		string a,b;
		cin >> a  >> b;

		int n = a.length();
		int m = b.length();

		int dp[n+1][m+1];
		int mlen = 0;
		memset(dp,0,sizeof(dp));
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(a[i-1] == b[j-1]){
					dp[i][j] = dp[i-1][j-1] +1;
					mlen=max(mlen,dp[i][j]);
				}
			}
		}
		vector<pair<int,pair<int,int>>> v1(n);
		vector<pair<int,pair<int,int>>> v2(m);
		for(int i=0;i<n;i++) v1.pb(make_pair(mlen,make_pair(mlen+1,mlen+2)));
		for(int i=0;i<m;i++) v2.pb(make_pair(mlen,make_pair(mlen+1,mlen+2)));


		cout << mlen <<endl;
	}
 	return 0;
}
