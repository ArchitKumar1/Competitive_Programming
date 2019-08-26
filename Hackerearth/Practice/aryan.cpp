#include<bits/stdc++.h>
using namespace std;
#define ll long long int      
void solve(){
   int n;
    cin >> n;
    int X ;
    cin >> X;
    priority_queue<long long int> pq;
    for(int i=0;i<n;i++){
        long long int a;
        cin >> a;
        if(a == 0){
            int cnt = X;
            for(int j=0;j<cnt;j++){
                if(!pq.empty()){
                    pq.pop();
                }
            }
        }
        else{
            pq.push(a);
        }
    }
    long long int sum = 0;
    while(!pq.empty()){
        sum+= pq.top();
        pq.pop();
    }
    cout << sum << endl;
    
}
        
    
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
}