#include<bits/stdc++.h>
using namespace std;


int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        int n,m,k,l,r;
        cin >> n >> m >> k >> l >> r;
        vector<pair<int,int>> all(n);
        for(int i=0;i<n;i++){
            cin >> all[i].second >> all[i].first;
        }
        sort(all.begin(),all.end());
        int ans =-1;
        for(int i=0;i<n;i++){
            int temp = all[i].second;
            int final;
            if(temp >= k){
                final = max(k,temp - m);
            }else{
                final = min(k,temp + m);
            }
            //cout << "F " << final << endl;
            if(final >= l && final <=r){
                ans = all[i].first;
                i = n;
            }
            
        }
        cout << ans << endl;
    }


}