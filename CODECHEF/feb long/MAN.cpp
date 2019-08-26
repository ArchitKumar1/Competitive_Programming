#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

int main()
{
	TC{
	int n;
	cin >> n;
	int a[n],d[n];
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<n;i++)
		cin>>d[i];
	int index=-1;
	for(int i=0;i<n;i++){
		if((d[i]-a[(i-1)%n]-a[(i+1)%n])>=0 && index<d[i]){
			index=max(index,d[i]);
		}
	}
	cout<<index<<endl;
	}
	return 0;
}


