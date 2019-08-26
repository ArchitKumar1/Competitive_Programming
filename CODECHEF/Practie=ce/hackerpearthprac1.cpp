#include<bits/stdc++.h>

#define ll long long
#define TC int t;cin>>t;while(t--)
using namespace std;



int main()
{

	TC{
		int  n;
		cin>>n;
		int arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i];
		}
		set<int > s;
		for(int i=0;i<n;i++){
			int x=arr[i];
			for(int j=2;j*j<=x;j++){
				if(x%j==0){
					s.insert(j);
					s.insert(x/j);
				}
			}
		}
		//sort(s.begin(),s.end());
		for(set<int>::iterator i=0;i<s.size();i++){
			cout<<*i<<" ";
		}

		cout<<s.size()<<endl;
	}
	return 0;
}

