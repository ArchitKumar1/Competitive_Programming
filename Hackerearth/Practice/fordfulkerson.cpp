#include<bits/stdc++.h>
using namespace std;
const int inf = 1 << 30;

int main(){

	const int N=10;
	int arr[N][N];
	int M=N;
	int stuff[100]={0};
	memset(arr,0,sizeof(arr));
	stuff[0]=M;
	M--;
	for(int i=1;i<100;i=i+2){
		if(M>0){
			stuff[i]=M;
			stuff[i+1]=M;
			M--;
		}
	}

	int i=0,j=0;
	int ind[4][2]={{0,1},{1,0},{0,-1},{-1,0}};
	int pos=0;
	int num=0;
	for(int k = 0;k<2*(N-1)+1;k++){
		for(int l=1;l<=stuff[k];l++){
			if(l!=stuff[k]){
				arr[i][j]=++num;
				if(l==stuff[k])
					pos=(pos+1)%4;
				i+=ind[pos][0];
				j+=ind[pos][1];
			}
		}

	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}

}
