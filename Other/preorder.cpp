#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define Forn(i,a,b) for(int i = a; i < b; i++)
#define pb push_back
using namespace std;


///////////////////////////
const int N = 100001;
int a[N]={0},vi[N]={0};
vector<int> adj[N];

/////////////////////////
void inorder(int s){
	vi[s] = 1;
	forn(i,2)
		if(!vi[adj[s][i]]){
			if(adj[s][0]) inorder(adj[s][0]);
			cout << s <<endl;
			if(adj[s][1]) inorder(adj[s][1]);
		}
}
int main(){
	int n;
	cin >> n;
	memset(adj,0,sizeof(adj));
	forn(i,n-1){
		int x,y;
		cin >> x >> y;
		x-- ;
		y-- ;
		adj[x][y] = 1;
		adj[y][x] = 1;
	}

	inorder(1);

	return 0;

}
