#include<bits/stdc++.h>
using namespace std;

int main()
{
	int t;
	cin >> t;
	while(t--){
		int n;
        cin >> n;
		vector<int> v;
		for(int i=0;i<n;i++){
			int x;
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(),v.end());
		int sum = 0;
		int cnt = 0;
		for(int i=0;i<n;i++){
			if(sum >= v[i]){
				cnt++;
				sum = sum + 1;
			}
			else break;
		}
		cout << cnt <<endl;

	}
	return 0;
}
