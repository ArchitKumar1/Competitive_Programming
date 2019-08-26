#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int s,n,x,y,a,b;
	cin>>s>>n;


	pair<int,int> apair;
    vector<pair<int,int> > vtemp(n);
    vector< vector<pair<int,int> > > darray;
	vector< vector<pair<int,int> > > ::iterator it2;
	vector<pair<int,int> >::iterator it1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			apair.first=0;
			apair.second=0;
			vtemp.push_back(apair);
			
		}
		darray.push_back(vtemp);
		vtemp.clear();
	}
	
	it2=darray.begin();
	vtemp=*it2;
	for(it1=vtemp.begin();it1!=vtemp.end();++it1)
	{
		cin>>a>>b;
		apair=*it1;
		apair.first=a;
		apair.second=b;


	}
	it2=darray.begin();
	vtemp=*it2;
	for(it1=vtemp.begin();it1!=vtemp.end();++it1)
	{


		apair=*it1;
		cout<<apair.first<<" "<<apair.second<<endl;
	}

	
	cout<<darray.size();
	
	
	
	
	
	
	

	return 0;
}
