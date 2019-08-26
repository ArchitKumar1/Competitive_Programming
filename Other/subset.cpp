#include<bits/stdc++.h>
using namespace std;  
  
int main()  
{  
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,y;
		cin>>n;
		int jafar[n][2];
//		for(int i=0;i<31;i++)
//		{
//			for(int j=0;j<2;j++)
//			{
//				jafar[i][j]=0;
//			}
//		}
//		for(int i=0;i<n;i++)
//		{
//			jafar[i][0]=x;
//			if(i==0)
//				jafar[i][1]=y;
//			else
//				jafar[i][1]=jafar[i-1][1]+y;
//		}
		for(int i=0;i<n;i++)
		{
			cin>>jafar[i][0]>>jafar[i][1];
		}
		int q;
		cin>>q;
		for(int i=0;i<q;i++)
		{
			cin>>x>>y;
			for(int j=0;j<n;j++)
			{
				if(x>=jafar[j][0])
				{
					int sum=0;
					for(int k=0;k<=j;k++)
						sum+=jafar[k][1];
					if(sum>=y)
					{
						cout<<"Go Camp"<<endl;
						break;	
					}
					else
						cout<<"Go Sleep"<<endl;
						break;
				}
				else
				{
				
					cout<<"Go Sleep"<<endl;
					break;
				}
					
			}
			
		}
} 
	return 0;
} 
