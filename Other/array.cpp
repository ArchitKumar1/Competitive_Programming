#include<bits/stdc++.h>
using namespace std;
#define ll long long
int array[1001][2002];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s,n,x,y,a,b;
	cin>>s>>n;
	for(int i=0;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		array[0][i]=x;
		array[1][i]=y;
	}

	for(int i=0;i<n;i++)
	{
		
		cout<<array[0][i]<<" "<<array[1][i]<<endl;
	}
	
	
	

	return 0;
}
