#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n;
	cin >> n;
	int a[n],dp[n+1]= {1};
	dp[0] = 0;

	for(int i=0;i<n;i++)
		cin >> a[i];

	for(int i=0;i<n;i++){
		if(a[i] < a[i-1])
			dp[i+1] = 1;
		else
			dp[i+1] = dp[i] + 1;
	}
	cout <<  *max_element(dp,dp+n+1);
	return 0;

}
