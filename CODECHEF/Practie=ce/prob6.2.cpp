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

int i,j;
int grid[50][50];
int cnt=0;

bool isSafe(int grid[50][50], int i, int j, int num,int m)
{
	int ul,ur,le,up;
    if(i<2) up=0; else up=grid[i-2][j];
	if(i==0 || j==m-1) ur=0; else ur=grid[i-1][j+1];
	if(i==0 || j==0) ul=0; else ul=grid[i-1][j-1];
	if(j<2) le=0; else le=grid[i][j-2];

	if(num!=up && num!=ur && num!=ul && num!=le)
		return 1;
	else
		return 0;
}
bool Solve(int grid[50][50],int n,int m)
{
    // If there is no unassigned location, we are done
    if (i==n-1 && j==m-1)
       return 1; // success!
	i=cnt%m;
	j=cnt/n;   // consider digits 1 to 9
    for(int num=1;num<=4;num++){
		if (isSafe(grid, i, j, num,m)){
				grid[i][j]=num;
				cnt++;
				if(Solve(grid,n,m))
					return true;

				grid[i][j]=0;
				cnt--;
		}

    }
    return false;
}






int main()
{
    int n,m;
    cin>>n>>m;

	cnt=(n-1)*(m-1);
    Solve(grid,n,m);
	for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
					if(j!=m-1)
						cout<<grid[i][j]<<" ";
					else
						cout<<grid[i][j];
		}
			cout<<endl;
	}
    return 0;
}
