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

	TC{
	int N,M,i,j;
	scanf("%d %d",&N,&M);
	ll min_salary[N],offered_salary[M];;
	char qual[N][M+2];
	ll max_job_offers[M],comphire[M]={0},totalN=0,totalM=0,totalsal=0;
	for(int i=0;i<N;i++) scanf("%lld",&min_salary[i]);
	for(int i=0;i<M;i++) scanf("%lld %lld",&offered_salary[i],&max_job_offers[i]);
	for(int i=0;i<N;i++) scanf("%s",&qual[i]);
	for(i=0;i<N;i++){
		ll select=-1,salary=0,cursalary=0;
		for(j=0;j<M;j++){
			if(qual[i][j]=='1'){
					if(max_job_offers[j]>0){
						if(min_salary[i]<=offered_salary[j]){
							select=j;
							if(offered_salary[j]>cursalary){
								select=j;
								cursalary=max(cursalary,offered_salary[j]);
							}
						}
					}
				}
		}
		if(select!=-1){
			max_job_offers[select]--;
			comphire[select]++;
			totalsal+=cursalary;
			totalN++;
		}
	}

	for(i=0;i<N;i++) if(comphire[i]==0) totalM++;
	printf("%lld %lld %lld",totalN,totalsal,totalM);
	printf("\n");
	}
	return 0;
}
