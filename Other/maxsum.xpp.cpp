#include<bits/stdc++.h>
using namespace std;
#define M 6
#define N 5
//typedef tuple <int,int,int,int> Point;
tuple <int,int,int,int> maxsum(int mat[][N],int k)
{
	int sum[M][N];
	sum[0][0]=mat[0][0];
	
	for (int j = 1; j < N; j++)
		sum[0][j] = mat[0][j] + sum[0][j - 1];

	for (int i = 1; i < M; i++)
		sum[i][0] = mat[i][0] + sum[i - 1][0];
		
		
	for(int i=1;i<M;i++)
		for(int j=1;j<N;j++)
			sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i][j];
	
			
	int total,max=INT_MIN,min=INT_MAX;
	
	Point p;
	int x1,y1;  
	int x2,y2;  
	for(int i=k-1;i<M;i++)
	{
		for(int j=k-1;j<N;j++)
		{
			total=sum[i][j];
			if (i - k >= 0)
				total = total - sum[i - k][j];
			if (j - k >= 0)
				total = total - sum[i][j - k];
			if(i-k>=0 and j-k>=0)
				total=total+sum[i-k][j-k];
			if(total>max)
			{
				max=total;
				x1=i;
				y1=j;
			}
			if(total<min)
			{
				min=total;
				x2=i;
				y2=j;
			}
			
		}
	}
	return make_tuple(x1,y1,x2,y2);

int main()
{
	
	int k=3;
	int mat[M][N]={{ 3, -4, 6, -5, 1 },{ 1, -2, 8, -4, -2 },{ 3, -8, 9, 3, 1 },{ -7, 3, 4, 2, 7 },	{ -3, 7, -5, 7, -6 },{4,3,1,92,8}}; 
	Point p=maxsum(mat,k);
	for(int i=0;i<M;i++)
	{
		for(int j=0;j<N;j++)
		{
			cout<<mat[i][j]<<"   ";
		}
		cout<<endl;
	}
	cout<<endl;
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			cout<<mat[get<0>(p)-k+i+1][get<1>(p)-k+j+1]<<"  ";
		}
		cout<<endl;
	}
	for(int i=0;i<k;i++)
	{
		for(int j=0;j<k;j++)
		{
			cout<<mat[get<2>(p)-k+i+1][get<3>(p)-k+j+1]<<"  ";
		}
		cout<<endl;
	}
	return 0;
}
