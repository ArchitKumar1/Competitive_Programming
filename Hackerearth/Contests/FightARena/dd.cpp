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
const int P = 1234;
vector<int> primes(P,1);
vector<int> allprimes;

int main(){
 
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    auto seive = [](){
        for(int i=2;i*i<=P;i++){
            if(primes[i] == 1){
                for(int j = i*i;j<P;j=j+i){
                    primes[j] = 0;
                }
            }
        }
        for(int i=2;i<P;i++){
            if(primes[i] == 1){
                allprimes.PB(i);
            }
        }
    };
    seive();
    int n;
    cin >> n;
    int l;
    cin >> l;
    int arr[n];
    forn(i,n) cin >> arr[i];

    int vals[l];

    for(int i=1;i<=l;i++){
        if(i == 1){
            vals[i] = 1;
            continue;
        }
        vector<pair<int,int>> facts;
        for(int j = 1;j*j<=i;j++){
            if(primes[j] == 1){
                if(i%j == 0){
                    int cnt = 0;
                    int cnt2 = 0;
                    int fake = i;
                    int fake2 = i;
                    if(j!= 1){
                        while(fake%j == 0){
                            cnt++;
                            fake = fake /j;
                        }
                        facts.PB({cnt,j});
                    }
                    int fakej = i/j;
                    if(primes[fakej] == 1 && fakej!=j){
                        while(fake2%fakej == 0){
                            cnt2++;
                            fake2 = fake2 /fakej;
                        }
                        facts.PB({cnt2,fakej});
                    }
                }
                
            }
        }
        // sort(ALL(facts));
        pair<int,int> temp = facts[0];
        if((temp.second % i)%2 == 1){
            vals[i] = 1;
        }else{
            vals[i] = 0;
        }
    }
    sort(arr,arr+n);

    int minpos = 0;
    int maxpos = n-1;
    // for(int i=1;i<=l;i++){
    //     cout << vals[i] << " ";
    // }
    for(int i=1;i<=l;i++){
        if(vals[i] == 0){
            A:
            if(minpos ==n){
                break;
            }
            if(arr[minpos]!=0){
                arr[minpos]/=2;
            }else{
                minpos++;
                goto A;
            }
        }else{
            arr[maxpos]*=2;
            arr[maxpos]%= mod;
        }
    //     for(int i=0;i<n;i++){
    //     cout << arr[i] << " ";
    // }
    // cout << endl;
    }
    int cnt = 0;
    for(int i=0;i<n;i++){
        cnt += arr[i]!=0;
    }
    cout << cnt << endl;
    for(int i=0;i<n;i++){
        if(arr[i]!=0){
            cout << arr[i] << " ";
        }
    }
    return 0;
}