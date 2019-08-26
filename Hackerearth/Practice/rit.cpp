#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;

const int maxn = 110000;
int a[maxn],b[maxn];

const int MAX = 56623;
class A{
public:
	A(){cout << "1";}
	virtual ~A() {cout << "2";}
};
class B :public A{
	public :
	B(){cout << "3";}
	~B(){cout << "4";}
};
int main()
{

	A* ptr = new B[2];
	delete [] ptr;

	#ifndef ONLINE_JUDGE
		cout << endl << endl <<endl <<endl;
		cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
	#endif

	return 0;

}
