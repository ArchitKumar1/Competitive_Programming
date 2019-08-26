#include<bits/stdc++.h>
#define ll long long
#define TC int t; cin>>t; while(t--)
using namespace std;
int main()
{
	int n=10;
	int dp[n+1];
	memset(dp,0,sizeof(dp));
	dp[1]=0;
	dp[2]=1;
	for(int i=3;i<=n;i++){
		int temp=-1;
		for(int j=1;j<i;j++)
			temp=max(j*max(i-j,dp[i-j]),temp);
		dp[i]=temp;
	}
	for(int i=1;i<=n;i++) cout<<dp[i]<<" ";
	return 0;
}

