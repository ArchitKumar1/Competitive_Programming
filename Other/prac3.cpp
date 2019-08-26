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
	string s1;
	cin>>s1;
	int l=s1.size();
	int dp[l+1]={0};
	for(int i=l-1;i>=0;i--){
		if((int(s1[i])-'0')%2==0)
			dp[i]=dp[i+1]+1;
		else
			dp[i]=dp[i+1];
	}
	for(int i=0;i<l;i++)cout<<dp[i]<<" ";
	return 0;
}
