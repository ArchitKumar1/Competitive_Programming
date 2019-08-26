#include<bits/stdc++.h>
//#include <boost/multiprecision/cpp_int.hpp>
//using boost::multiprecision::cpp_int
#define ll long long
#define TC int t;cin>>t;while(t--)
using namespace std;
const int N=1000;
ll dp[N][N];

int main()
{
	ll n,i,j;
	for(i=0;i<N;i++)
		dp[i][0]=0;
	
	for(i=0;i<N;i++)
		dp[0][i]=1;
	for(j=1;j<N;j++)
	{
		for(i=1;i<=j;i++)
		{
			if(i==j)
				dp[i][j]=1;
			else
				dp[i][j]=dp[i][j-1]+dp[i-1][j-1];
		}
	}
	cout<<dp[10][450]<<endl;
	return 0;
}

