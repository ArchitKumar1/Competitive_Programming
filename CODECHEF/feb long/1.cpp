#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

int main(){
	TC{

	int n;
	cin >> n;
	int a[n],d[n];

	forn(i,n) cin >> a[i];
	forn(i,n) cin >> d[i];
	int def = -1;

	forn(i,n){
		if( i==0)
			if(d[i] > (a[i+1] + a[n-1]) && d[i] > def)
				def = d[i];
		else if (i == n-1)
			if(d[i] > (a[0] + a[i-1]) && d[i] > def)
				def = d[i];
		else
			if(d[i] > (a[i+1] + a[i-1]) && d[i] > def)
				def = d[i];
	}
	cout << def <<endl;
	}
	return 0;

}
