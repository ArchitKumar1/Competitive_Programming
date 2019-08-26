#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;
typedef vector<int,int> vdi;
typedef vector<int> vi;
vector<Pair> v1;


int main()
{

	int m=5,n=5;
	int num[m][n]={{1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9}},sum[m][n]={0};
	sum[0][0]=num[0][0];
	for(int i=1;i<m;i++) sum[i][0]=sum[i-1][0]+num[i][0];
	for(int i=1;i<n;i++) sum[0][i]=sum[0][i-1]+num[0][i];
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+num[i][j];
		}
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<sum[i][j]<<" ";
		}
		cout<<endl;
	}
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<num[i][j]<<" ";
		}
		cout<<endl;
	}
	int temp;
	int maxsum=0,k=3;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
		    if(i>=k && j>=k){
				temp=sum[i][j]-sum[i-k][j]-sum[i][j-k]+sum[i-k][j-k];
				maxsum=max(temp,maxsum);
		    }
		}
	}
	cout<<maxsum<<endl;

	return 0;
}
