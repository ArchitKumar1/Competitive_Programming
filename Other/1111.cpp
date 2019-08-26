#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	srand(time == NULL);
	int n = 10000,sum = 9000 ,a = 0, c = 1; int arr[n];	map<int,int> m;
	for(int i = 0; i < n; i++){ arr[i] = rand() % 10000; m[arr[i]]++;}
	for(int i = 0; i < n; i++) if(m[sum - arr[i]])cout << arr[i] << " " <<sum - arr[i] << " " << c++<< "\n";
	return 0;
}
