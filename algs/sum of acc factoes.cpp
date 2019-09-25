//Author - archit //
#include<bits/stdc++.h>
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){
    os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){
    return os<<"("<<P.first<<","<<P.second<<")";
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
		const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...) 1
#endif

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)

#define ALL(x) x.begin(),x.end()
#define LL long long int
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define endl "\n"

typedef pair<int,int>PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<PII> VPII;

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

/////////////////////////////
const int N = 1000;
vector<int> prime(N,1),all;

void seive(){
    for(int i = 2;i*i<=N;i++){
        if(prime[i] == 1){
            for(int j = i*i;j<N;j=j+i){
                prime[j] = 0;
            }
        }
    }
}
int sumofFactors(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= sqrt(n); i++) 
    { 
        int curr_sum = 1; 
        int curr_term = 1; 
        while (n % i == 0) { 
            n = n / i; 
            curr_term *= i; 
            curr_sum += curr_term; 
        } 
        res *= curr_sum; 
    } 
    if (n >= 2) 
        res *= (1 + n); 
    return res; 
}     
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    seive();
    auto findfacts = [&](int n){
        int ans = 1;
        for(int i =2;i*i<=n;i++){
            if(prime[i] && n%i == 0){
                int cnt = 0;
                while(n%i == 0){
                    cnt++;
                    n = n/i;
                }
                int tsum = (pow(i,cnt+1)-1)/(i-1);
               // trace(tsum,cnt,i);
                ans*= tsum;
            }
        }
        if(n>=2){
            ans*= (1+n);
        }
        return ans;
    };
    int n;
    cin >> n;
    cout << findfacts(606);
    cout << endl << sumofFactors(606);
}