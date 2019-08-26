#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;
typedef vector<int,int>  vdi;
typedef vector<int> vi;
vector<Pair> v1;


int getv(int a,int b,int c,int d,int arr[]){
	for(int i=0;i<4;i++){
		if(arr[i]!=a && arr[i]!=b && arr[i]!=c && arr[i]!=d)
			return arr[i];
	}
	return 0;
}
int main()
{

	int t;
	cin>>t;
	int a[2][t];
	for(int i=0;i<t;i++){
		cin>>a[0][i]>>a[1][i];
	}
	for(int i=0;i<t;i++){


		int n,m;
		n=a[0][i];
		m=a[1][i];
		int grid[n][m];
		int arr[4]={1,2,3,4};
		int ma=0;
		int ur,ul,le,up;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(i<2) up=0; else up=grid[i-2][j];
				if(i==0 || j==m-1) ur=0; else ur=grid[i-1][j+1];
				if(i==0 || j==0) ul=0; else ul=grid[i-1][j-1];
				if(j<2) le=0; else le=grid[i][j-2];

				grid[i][j]=getv(ur,ul,up,le,arr);
				ma=max(ma,grid[i][j]);
			}
		}
		cout<<ma<<endl;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
					if(j!=m-1)
						cout<<grid[i][j]<<" ";
					else
						cout<<grid[i][j];
			}
			cout<<endl;
		}
	}
	return 0;
}
