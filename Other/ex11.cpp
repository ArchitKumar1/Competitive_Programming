#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e9 +7;
typedef pair<int,int> Pair;
typedef vector<int> vi;

const int MAX=51000;
int primes[MAX];

int main()
{
	int c=0;
	for(int i=0;i<650000;i++ ){
		for(int j=2;i*i<=j;j++){
			if(i%j==0){
				break;
			}
			primes[c++]=i;
		}
	}
	for(int i=0;i<c;i++){
		cout<<primes[c++]<<endl;
	}
	return 0;
}
