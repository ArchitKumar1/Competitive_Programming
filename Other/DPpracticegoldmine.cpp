#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

const int MAX=4;
typedef pair<int,int> Pair;
typedef vector<int> vi;
typedef vector<Pair> vpair;
int main()
{
	fastio
	int gold[MAX][MAX]= { {1, 3, 1, 5},{2, 2, 4, 1},{5, 0, 2, 3},{0, 6, 1, 2}};
    int m=4,n=4;

    int goldtable[m][n];

    memset(goldtable,0,sizeof(goldtable));
    int r,ru,rd;
    for(int col=n-1;col>=0;col--){
		for(int row=0;row<m;row++){
		if(col==n-1)
			r=0;
		else
			r=goldtable[row][col+1];
		if(row==0 || col==n-1)
			ru=0;
		else
			ru=goldtable[row-1][col+1];
		if(row==m-1 || col==n-1)
			rd=0;
		else
			rd=goldtable[row+1][col+1];
		goldtable[row][col]=gold[row][col]+max(r,max(ru,rd));
		}
    }
    int x=goldtable[0][0];
    for(int i=0;i<m;i++){
		x=max(x,goldtable[i][0]);
    }
    cout<<x;
	return 0;
}
