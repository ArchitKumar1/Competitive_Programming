#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	while(t--)
	{
		string n;
		cin>>n;
		ll m=0;
		for(int i=0;i<n.length();i++)
		{
			m=(m+n[i]-'0')%9;
			
		}
		if(m==0)
			cout<<0<<endl;
		else
		{
			ll u=0,d=0;
			int difference;
			for(int i=0;i<n.length();i++)
			{
				difference=n[i]-'0';
				
				u+=9-difference;
				d+=difference;
			}
			if(n.length()!=1)
			{
				d-=(n[0]-'0');
			}
			if(m<=4)
			{
				if(d>=m)
					cout<<m<<endl;
				else
					cout<<9-m<<endl;
			}
			else
			{
				m=9-m;
				if(u>=m)
					cout<<m<<endl;
				else
					cout<<9-m<<endl;
			}
			
		}
	}
	return 0;
	
}
//#include<bits/stdc++.h>
//using namespace std;
//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL);
//	int t;
//	cin>>t;
//	while(t--)
//	{
//		string n;
//		cin>>n;
//		long long m=0;
//		for(int i=0;i<n.length();i++)
//			m=(m+n[i]-'0')%9;
//		if(m==0)
//			cout<<0<<endl;
//		else
//		{
//			//determine possible up/down
//			long long u=0,d=0;
//			int di;
//			for(int i=0;i<n.length();i++)
//			{
//				di=n[i]-'0';
//				
//				u+=(9-di);
//				d+=di;
//			}
//			if(n.length()!=1)
//			{
//				d-=(n[0]-'0');
//			}
//			if(m<=4&&d>=m)
//				cout<<m<<endl;
//			else if(m<=4&&d<m)
//				cout<<9-m<<endl;
//			else
//			{
//				m=9-m;
//				if(u>=m)
//					cout<<m<<endl;
//				else
//					cout<<9-m<<endl;
//			}
//		}
//	}
//}
