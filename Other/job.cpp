#include<bits/stdc++.h>
using namespace std;
int main()

{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t;
	cin>>t;
	for(int k=0;k<t;k++)
	{
	int N,M,i,j;
	cin>>N>>M;
	long long min_salary[N];
	long long offered_salary[M];
	char qual[N][M+2];
	long long max_job_offers[M];
	long long comphire[M];
	long long totalN=0;
	long long totalM=0;
	long long totalsal=0;
	
	for(i=0;i<M;i++)	{
		comphire[i]=0;
	}
	for(i=0;i<N;i++){
		cin>>min_salary[i];
	}
	for(i=0;i<M;i++){
		cin>>offered_salary[i]>>max_job_offers[i];
	}
	for(int i=0;i<N;i++)
		scanf ("%s", qual[i]);
	for(i=0;i<N;i++)
	{
		long long select=-1;
		long long salary=0;
		long long cursalary=0;

		for(j=0;j<M;j++)
		{
			if(qual[i][j]=='1')
				{
					if(max_job_offers[j]>0)
					{
						if(min_salary[i]<=offered_salary[j])
						{
							select=j;
							if(offered_salary[j]>cursalary)
							{
								select=j;
								cursalary=max(cursalary,offered_salary[j]);
							}
						}
					}
				}
		}
		if(select!=-1)
		{
		max_job_offers[select]--;
		comphire[select]++;
		totalsal+=cursalary;
		totalN++;
		}
	}
	
	for(i=0;i<N;i++)
	{
		if(comphire[i]==0)
			totalM++;
	}
	cout<<totalN<<" "<<totalsal<<" "<<totalM;
	}
	return 0;
}

