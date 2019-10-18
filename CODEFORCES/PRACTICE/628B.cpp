#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;

int ask(int l,int r){
	cout << "? ";
	for(int i=l;i<=r;i++){
		cout << i << " ";
	}
	cin >> ans;
	return ans;
}
int main()
{

	#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	#endif
o
	int n,x,y;
	cin >> n >> x  >> y;
	int ans  = -1;
	left = 0; right = n-1;
	while(ans!==-1)	{
		int a = ask(left,right/2);
		int b = ask(right/2,right);

		if(a == B)
	}


	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif

	return 0;

}
