#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

int main(){
	fastio
	TC{
	int n;
	cin>>n;
	int a[n],d[n],ma[n],m=INT_MIN,index;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++) cin>>d[i];
	for(int i=0;i<n;i++){
		if(i==0)
			ma[i]=d[i]-a[n-1]-a[i+1];
		else if(i==n-1)
			ma[i]=d[i]-a[i-1]-a[0];
		else
			ma[i]=d[i]-a[i-1]-a[i+1];
		if(ma[i]>m){
			m=ma[i];
			index=i;
		}
	}
	if(m>0) cout<<d[index]<<endl<<flush;
	else cout<<"-1"<<endl<<flush;
	}
	return 0;

}
