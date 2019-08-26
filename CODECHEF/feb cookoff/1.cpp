#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n,b;
		cin >> n >> b;
		int area = 0;
		for(int i=0;i<n;i++){
			int w,h,p;
			cin >> w >> h >> p;
			if(h*w > area && p<=b){
				area = h*w;
			}
		}
		if(area == 0)
			cout<< "no tablet " <<endl;
		else cout<< area <<endl;
	}
	return 0;
}
