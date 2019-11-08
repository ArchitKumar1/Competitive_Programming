#include<bits/stdc++.h>
using namespace std;
typedef complex<double> base;
typedef long double ld;
typedef long long ll;
#define pb push_back
const int maxn=(int)(2e5+5),LN=41;
const ll mod=(ll)(1e9+7);
ld pi=2.0*acos(0.0);
ll a[maxn];
int pre[LN][maxn];
int mul(ll a,ll b)
{
	a%=mod;b%=mod;
	
	ll ret=(a*b);
	
	if(ret>=mod)
	{
		ret%=mod;
	}
	
	return (int)ret;
}
int add(ll a,ll b)
{
	a%=mod;b%=mod;
	
	ll ret=a+b;
	
	if(ret>=mod)
	{
		ret%=mod;
	}
	
	return (int)ret;
}
int sub(ll a,ll b)
{
	a%=mod;b%=mod;
	
	ll ret=a-b;
	
	if(ret<0)
	{
		ret+=mod;
	}
	
	return (int)ret;
}
static int poww(ll a,ll b)
{
	ll x=1,y=a;
		
	while(b>0)
	{	
		if(b%2)
		{
			x=mul(x,y);
		}
			
		y=mul(y,y);b/=2;
	}
		
	return (int)(x%mod);
}
const int inv_6=poww(6,mod-2),inv_2=poww(2,mod-2);
int nC3(ll n)
{
	if(n<3)
	{
		return 0;
	}
	
	return mul(mul(n,mul(n-1,n-2)),inv_6);
}
int nC2(ll n)
{
	if(n<2)
	{
		return 0;
	}
	
	return mul(n,mul(n-1,inv_2));
}
int main()
{	
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
	int n;scanf("%d",&n);
	
	assert(n>=1 && n<=(int)(1e5));
	
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		
		assert(a[i]>=1 && a[i]<=(ll)(1e12));
	}
	
	for(int j=0;j<LN;j++)
	{
		int now=0;ll zz=(1ll<<j);
		
		for(int i=1;i<=n;i++)
		{
			if((zz&a[i])!=0)
			{	
				now++;
			}
			
			pre[j][i]=now;
		}
	}
	
	int q,two;scanf("%d%d",&q,&two);
	
	assert (q>=1 && q<=(int)(5e5) && two==2);
	cout << inv_2 << " " << inv_6 << endl;
	for(int i=0;i<q;i++)
	{
		int l,r;
        scanf("%d%d",&l,&r);
		
		assert (l>=1 && l<=r && r<=n);
		
		int res=0,size=(r-l+1);
		
		for(int j=0;j<LN;j++)
		{
			int val1=(pre[j][r]-pre[j][l-1]),val0=size-val1;
            cout << i << " "<< j << " " << val1 <<endl;
			
			int zz1=mul(val1,nC2(val0)),zz2=nC3(val1);
			
			res=add(res,mul(1ll<<j,add(zz1,zz2)));
		}
		
		printf("%d\n",res);
	}
	
	return 0;
}
