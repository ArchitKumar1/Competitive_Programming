#include<bits/stdc++.h>
using namespace std;

#define ALL(x) x.begin(),x.end()
#define LL long long int
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define endl "\n"
#define l() cout << endl;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////
const LL N = 2345;

vector<LL> powers(N,0);
LL C[N + 1][N + 1];

void add(LL &a,LL b){
    a = a%mod;
    b = b%mod;
    a = (a+b)%mod;
}
void mul(LL &a,LL b){
    a = (a*b)%mod;
}
void help(){
    powers[0] = 1;
    for(LL i=1;i<N;i++){
        powers[i] = powers[i-1]*2;
        powers[i]%=mod;
    }
     
    LL i, j; 

    for (i = 0; i <= N; i++) 
    { 
        for (j = 0; j <= min(i, N); j++) 
        { 
            if (j == 0 || j == i) 
                C[i][j] = 1; 
            else
                C[i][j] = (C[i - 1][j - 1] + C[i - 1][j])%mod; 
        } 
    } 
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
help();
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        LL arr[n+1];
        forn(i,n){
            cin >> arr[i+1];
        }
        vector<LL> ans(n+1,0);
        
        for(LL i=1;i<=n;i++){
            for(LL j = i;j<=n;j++){
                LL rans = powers[n-j];
                LL lans = C[j-1][i-1];
                //f(lans<0 || rans< 0)trace(rans,lans,arr[j]);
                if(lans == 0){
                    LL total = rans;
                    LL totalans = (arr[j]*total)%mod;
                    ans[i] = ans[i] + totalans;
                    ans[i]%= mod;
                }
                //else ans[i] +=(arr[j]*(rans*lans)%mod)%mod;
                else{
                    LL total = (rans*lans)%mod;
                    LL totalans = (arr[j]*total)%mod;
                    ans[i] = ans[i] + totalans;
                    ans[i]%= mod;
                }
                
                
                //trace(arr[j],lans,rans,j,i);
                
            }
        }
        for(LL i=1;i<=n;i++){

            cout << ans[i];
            if(i!=n) cout << " ";
        }
        cout << endl;
    }
    
    
    
}




