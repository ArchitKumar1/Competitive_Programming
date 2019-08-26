#include<bits/stdc++.h>
using namespace std;

void printarray(int array[][5])
{
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			cout<<array[i][j]<<" ";
		}
		cout<<endl;
	}
}
int main()
{
	int n=5,i,j;
	int a[5][5];
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			a[i][j]=i+j;
	printarray(a);
	return 0;
}
