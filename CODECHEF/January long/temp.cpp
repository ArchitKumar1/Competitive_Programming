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
bool isprime(int n){
	for(int i=2;i*i<=n;i++)if(n%i==0) return false;
	return true;
}

int arr[4]={1,2,3,4};
int getv(int a,int b,int c,int d){
	for(int i=0;i<4;i++){
		if(arr[i]!=a && arr[i]!=b && arr[i]!=c && arr[i]!=d)
			return arr[i];
	}
}
int main()
{

	int grid[50][50];
	int m=50,n=50;
	int ur,ul,le,up;
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			if(i<2) up=0; else up=grid[i-2][j];
			if(i==0 || j==m-1) ur=0; else ur=grid[i-1][j+1];
			if(i==0 || j==0) ul=0; else ul=grid[i-1][j-1];
			if(j<2) le=0; else le=grid[i][j-2];

			grid[i][j]=getv(ur,ul,up,le);
			cout<<ur<<" "<<ul<<" "<<up<<" "<<le<<endl;
			cout<<getv(ul,up,le,ur)<<endl;
		}
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<5;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}

	return 0;
}
