#include<bits/stdc++.h>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<pair<int,int> > v(n);
		for(int i=0;i<n;i++)
		{
			int x,y;
			cin>>x>>y;
			v.push_back(make_pair (x,y));
		}
		vector<pair<int,int> >:: iterator it;
		for (it = v.begin(); it != v.end(); ++it) 
		{
			cout<<(*it).first<<" "<<(*it).second<<endl;
		}
	}
	return 0;
}
