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
	fastio
	int q;
	cin >> q;
	int h=0,w=0;
	char a;
	int b,c;
	for(int i = 0; i < q; i++){
		cin>>a>>b>>c;
		if(a=='+'){
			if(b<c) swap(b,c);
			h=max(h,b);
			w=max(w,c);

		}
		else{
			if(b<c) swap(b,c);
			if((h<=b && w<=c ))
				cout<<"YES"<<endl;
			else
				cout<<"NO"<<endl;
		}
	}
	return 0;
}
