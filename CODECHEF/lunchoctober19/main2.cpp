#include<bits/stdc++.h>
using namespace std;

const int NAX = 1e7;
int orgi[NAX];
int fina[NAX];
int M= 1234;


int temporary[100];
long long int ans = 0;
void helper(int a,int b,int c){
    for(int i=0;i<a;i++){
        for(int j=0;j<b;j++){
            for(int k=0;k<c;k++){
                temporary[i] = j+k;
            }
        }
    }
}
void newlyarrange(int *orgi,int start,int mid,int end){
    int newmerger[end-start+1];
    int abra = start;
    int babra = mid+1;
    int k = 0;
    for(int i= start;i<=end;i++){
        if(abra>mid) newmerger[k++] = orgi[babra++];
        else if(babra>end) newmerger[k++] = orgi[abra++];
        else if(orgi[abra] <= orgi[babra]) newmerger[k++] = orgi[abra++];
        else newmerger[k++] = orgi[babra++],ans+= mid-abra+1;
    }
    for(int i=0;i<k;i++){
        orgi[start++] = newmerger[i];
    }
}
    
void combinator(int* orgi,int start,int end){
    if(start<end){
        int mid = (start+end)/2;
        combinator(orgi,start,mid);combinator(orgi,mid+1,end);newlyarrange(orgi,start,mid,end);
    }
}
int main(){
 #ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    int t;
    cin >> t;
    while(t--){
        int number;
        cin >> number;
        int queries;
        cin >> queries;
        for(int i=0;i<number;i++){
            cin >> fina[i];
        }

        while(queries--){
            int k;
            cin >> k;
            for(int i=0;i<number;i++){
                orgi[i] = fina[i] ^ k;
            }
            ans = 0;
            combinator(orgi,0,number-1); 
            cout << ans << endl;
        }
    }
    
   
    return 0;
}