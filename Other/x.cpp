#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;


struct Point{
	int x;
	int y;

	int operator+(Point const &p){
		return (x+y+p.x+p.y);
	}
	int operator-(Point const &p){
		return (x+y-p.x-p.y);
	}
	int operator*(Point const &p){
		return (x*p.x+y*p.y);
	}
	int operator/(Point const &p){
		return (x/p.x +y/p.y);
	}
};

ll arrperm[500][500]={0};
ll arrcomb[500][500]={0};
int main()
{
	int n,r;
	cin >> n >> r;
	for (int i=0;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(i==0)
				arrcomb[i][j]=1;
			else
				arrcomb[i][j]=arrcomb[i][j-1]+arrcomb[i-1][j-1];
		}
	}
//	for (int i=0;i<=n;i++)
//	{
//		for(int j=0;j<=n;j++)
//		{
//			cout<<arrcomb[i][j]<<" ";
//
//		}
//		cout<<endl;
//	}

	cout<<arrcomb[r][n]<<endl;
	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}
