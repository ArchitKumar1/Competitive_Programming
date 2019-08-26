#include<bits/stdc++.h>
using namespace std;
void display(vector<vector< tuple< int,int,int >>>& v2)
{

	for(int i=0;i<v2.size();i++)
	{
		
		for(int j=0;j<v2[i].size();j++)
		{
			cout<<get<0>(v2[i][j])<<" "<<get<1>(v2[i][j])<<" "<<get<2>(v2[i][j])<<endl;
		}
	}
	cout<<endl;
}
int main()
{
	int n,x,y;
	cin>>n;
	vector<vector<tuple<int,int,int> > > v2;
	vector<tuple<int,int,int> > v1;
	for( int i=0;i<n;i++)
	{
		cin>>x;
		cin>>y;
		v1.push_back(make_tuple(x,y,z));
	}
	v2.push_back(v1);
	display(v2);

	return 0;
	
}

