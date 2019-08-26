#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);


int main()
{
	map<int,int> m1;
	for(int i=0;i<5;i++){
		int x,y;
		cin>>x>>y;
		m1[x]=y;
	}
	sort(m1.begin(),m1.end());
	for(map<int,int>::iterator it=m1.begin();it!=m1.end();it++){

		cout<<(*it).first<<" "<<(*it).second<<endl;
	}
	return 0;
}
