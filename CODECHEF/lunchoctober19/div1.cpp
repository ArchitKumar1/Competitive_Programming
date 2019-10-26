#include<bits/stdc++.h>
using namespace std;

#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)

/////////////////////////////


int main(){
 #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    TC{
        int n;
        cin >> n;
        vector<int> all(n);
        for(int  &c: all){
            cin >>c ;
        }
        sort(all.begin(),all.end());
        int m = unique(all.begin(),all.end())-all.begin();
        reverse(all.begin(),all.end());

        if(m%4 == 0){
            vector<int>temp;
            for(int i=1;i<=3;i++){
                
                temp.push_back(all[3*i/4]);
            }
            sort(temp.begin(),temp.end());
            for(int i=0;i<3;i++){
                cout << temp[i] << " ";
            }
            cout << endl;
        }else{
            cout << "-1" << endl;
        }

    }
    
   
    return 0;
}



