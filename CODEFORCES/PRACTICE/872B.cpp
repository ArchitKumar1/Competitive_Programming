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

const int mod = pow(10,9)+7;
const double inf = 1e18;
const LL linf = 2e18;
const double eps = 1e-9;

//////////////////////////////////////////////


const int K = 40;
const int N = 1.1e5;

LL sparse1[N][K];

LL solve1(int l,int r){
    int k = floor(log2(r-l+1));
    return min(sparse1[l][k],sparse1[r - (1LL<<k)+1][k]);
}

int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
//     cout.precision(1);
//     cout << fixed;
//     int n;
//     cin >> n;
    
//     forn(i,n){
//         cin >> arr[i];
//     }
//     for(int i=0;i<n;i++){
//         sparse1[i][0]= arr[i];
//         sparse2[i][0]= arr[i];
//     }
//     for(int j =1;j<K;j++){
//         for(int i =0;i+(1<<j)-1 <n;i++){
//             sparse1[i][j] = max(sparse1[i][j-1] ,sparse1[i+(1<<(j-1))][j-1]);
//             sparse2[i][j] = min(sparse2[i][j-1] ,sparse2[i+(1<<(j-1))][j-1]);
//         }
//     }
//     int t;
//     cin >> t;
//     while(t--){
//         int l,r;
//         cin >> l >> r;
//         double leftmax =0,rightmax = 0;
//         if(l==0)leftmax =0;
//         else leftmax = solve1(0,l-1);
//         if(r == n-1) rightmax = 0;
//         else rightmax = solve1(r+1,n-1);

//         double middlemax = solve1(l,r);
//         double middlemin = solve2(l,r);

//      //  trace(leftmax,middlemax,middlemin,rightmax);
//    //   cout << leftmax <<endl;

//         cout << max({leftmax+middlemin,(middlemax+middlemin)/2,rightmax + middlemin}) << endl;

//    }
    LL n;
    cin >> n;
    LL k;
    cin >> k;
    vector<LL> arr(n);
    forn(i,n) cin >> arr[i];
    if(k == 1){
        cout << *min_element(ALL(arr));
    }else if(k == 2){
        for(LL i=0;i<n;i++){
            sparse1[i][0] = arr[i];
        }
        for(LL j = 1;j<K;j++){
            for(LL i=0;i + (1LL << j)-1 <n;i++ ){
                sparse1[i][j] = min(sparse1[i][j-1],sparse1[i+(1LL<<(j-1))][j-1]);
            }
        }
        LL fans = INT_MIN;
        for(LL i=0;i+1<n;i++){
            //trace(solve1(0,i));
          //  trace(solve1(i+1,n-1));
            fans = max(fans,max(solve1(0,i),solve1(i+1,n-1)));
        }
        cout << fans << endl;
        //cout << max(arr[0],arr[n-1]);
    }else{
        cout << *max_element(ALL(arr));
    }
#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}