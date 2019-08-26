#include<bits/stdc++.h>
#define forn(i,n) for(int i=0;i<n;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
using namespace std;

const int inf = 1 << 30;

map<int,int> la;
map<int,int> sn;

int main()
{

#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#endif
		int l; cin >> l;
		forn(i,l){
			int x,y;
			cin >> x >> y;
			la[x] = y;
		}
		int s; cin >> s;
		forn(i,s){
			int x,y;
			cin >> x >> y;
			sn[x] = y;
		}
		int dp[101];
		forn(i,101)
			dp[i] = inf;
        dp[1] = 0;

        for(int i=2;i<=100;i++){
            for(int j=1;j<=6 ;j++){
                if((i-j) >= 1){
                    if(sn[i]==0){
                        if(la[i-j]!=0)
                            dp[i] = min(dp[i],1 + dp[la[i-j]]),cout << "HI" <<endl;
                        else
                            dp[i] = min(dp[i], 1 + dp[i-j]);
                    } else {
                      if (la[i - j] != 0)
                        dp[sn[i]] = min(dp[sn[i]], 1 + dp[la[i - j]]);
                      else
                        dp[sn[i]] = min(dp[sn[i]], 1 + dp[i - j]);
                    }
                }
            }
        }
        forn(i,101){
        	cout << dp[i] << " ";
        	if(i%10 == 0)
        	cout <<endl;
        }
		cout << dp[100] <<endl;
		cout << la[10] << endl;
#ifndef ONLINE_JUDGE
	cout << endl << endl <<endl <<endl;
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}

