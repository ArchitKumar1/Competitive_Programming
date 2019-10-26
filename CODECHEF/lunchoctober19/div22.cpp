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
        int k;
        cin >> k;
        int arr[n];
        for(int i=0;i<n;i++){
            cin >> arr[i];
        }

        
        long long fans = 0;
        forn(i,n){
            int big = 0;
            int big2 = 0;
            forn(j,n){
                if(i == j) continue;
                if(arr[i] > arr[j]) big++;
            }
            for(int j = i+1;j<n;j++){
                if(arr[i] > arr[j]) big2++;
            }
            
            fans += (long long int)big*(k)*(k-1)/2 + big2*(k);
        }
        cout << fans << endl;
            
    }
    
   
    return 0;
}



