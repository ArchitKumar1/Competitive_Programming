#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	int t;
	cin >> t;
	while(t--){
	int n;
	cin >> n;
	ll ans=0;
	ll x;
	for(int i=0;i<n;i++){
		cin >> x;
		ans+= x-1;
	}
	ans++;
	cout << ans <<endl;
	}
	return 0;
}
