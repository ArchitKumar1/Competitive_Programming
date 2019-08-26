#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;
const int MAX=100010;
ll height[MAX];
int main()
{

	int n,h;
	cin >> n >>h;

	for(int i=0;i<n;i++) cin>>height[i];
	int input=-1;
	int pos=0;
	int hold=0;
	while(input!=0){

		cin>>input;
		if(input==0)
			break;
		if(input==1){
			if(pos!=0)
				pos=pos-1;
		}
		else if(input==2){
			if(pos!=n-1)
				pos=pos+1;
		}
		else if(input==3){
			if(height[pos]!=0 && hold==0){
				hold++;
				height[pos]--;
			}

		}
		else if(input==4){
			if(height[pos]!=h && hold==1){
				hold--;
				height[pos]++;
			}

		}
	}
	for(int i=0;i<n;i++) cout<<height[i]<<" ";
	cout<<endl;
	return 0;
}
