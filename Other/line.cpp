#include<bits/stdc++.h>
using namespace std;
#define ll long long 

const double error=1e-6;

char logo[3][3];
int main()
{
	ios::sync_with_stdio(false);
	int n,k,p;
	int t;
	cin>>t;
	while(t--)
	{
		for(int i=0;i<3;i++)
			cin>>logo[i];
		int r=0;
		for(int i=0;i<2;i++)
		{
			for(int j=0;j<2;j++)
			{
				if(logo[i][j]=='l' && logo[i+1][j]=='l' && logo[i+1][j+1]=='l')
					r=1;
					break;
				
			}
		}
		if(r==1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
