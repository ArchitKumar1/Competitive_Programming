#include<bits/stdc++.h>
using namespace std;
#define mod 100000007
#define ll long long 
#define N 3
int main() 
{ 
	int x,y;
	
    vector< pair<int,int> > v1(N);
    for(int i=0;i<N;i++)
    {
    	cin>> x>> y;
    	pair<int,int>p =make_pair(x,y);
    	v1.push_back(p);
	}
	for(int i=0;i<N;i++)
    {
    	cout<<(*v1[i].first)<<" "<<(*v1[i].second)<<endl;
	}
	return 0;
} 
