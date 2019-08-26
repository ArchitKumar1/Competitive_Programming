#include<bits/stdc++.h>
using namespace std;
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	const int N=5;
	int arr[N][N];
	int M=N;
	int stuff[2*(N-1)+1]={0};
	stuff[0]=M;
	M-- ;
	for(int i=1;i< 2*(N-1)+1;i=i+2){
		stuff[i]=M;
		stuff[i+1]=M;
		M--;
	}
	int i=0,j=0,pos=0,num=0;
	int ind[4][2]={{0,1},{1,0},{0,-1},{-1,0}};

	for(int k = 0; k < 2*(N-1)+1; k++){
		for(int l = 1; l <= stuff[k]; l++){
			arr[i][j]=++num;
			if(l==stuff[k]) pos=(pos+1)%4;
			i+=ind[pos][0];
			j+=ind[pos][1];
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout.width(5);
			cout<<left<<arr[i][j];
		}
		cout<<endl;
	}
	for(int i : stuff){
		cout << i << " ";
	}
	return 0;
}
