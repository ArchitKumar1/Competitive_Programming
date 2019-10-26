#include<bits/stdc++.h>
using namespace std;

#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)



/////////////////////////////


const int N = 1234567;

int arr[N];
int brr[N];
long long int ans = 0;
void merge(int *arr,int s,int m,int e){
    int temp[e-s+1];
    int p = s;
    int q = m+1;
    int k = 0;
    for(int i= s;i<=e;i++){
        if(p>m) temp[k++] = arr[q++];
        else if(q>e) temp[k++] = arr[p++];
        else if(arr[p] <= arr[q]) temp[k++] = arr[p++];
        else temp[k++] = arr[q++],ans+= m-p+1;
    }
    for(int i=0;i<k;i++){
        arr[s++] = temp[i];
    }
}
    
void msort(int* arr,int s,int e){
    if(s<e){
        int m = (s+e)/2;
        msort(arr,s,m);
        msort(arr,m+1,e);
        merge(arr,s,m,e);
    }
}
int main(){
 #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    TC{
        int n;
        cin >> n;
        int q;
        cin >> q;
        for(int i=0;i<n;i++){
            cin >> brr[i];
        }

        while(q--){
            int k;
            cin >> k;
            forn(i,n){
                arr[i] = brr[i] ^ k;
            }
            ans = 0;
            msort(arr,0,n-1);
            
            cout << ans << endl;
        }
    }
    
   
    return 0;
}



