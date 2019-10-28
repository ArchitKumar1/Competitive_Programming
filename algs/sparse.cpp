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

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


const int MAX= 50000;
const int LOGMAX = 30;
int table[MAX][LOGMAX]; 
  
// it builds sparse table. 
void buildSparseTable(int arr[], int n) 
{ 
    // GCD of single element is element itself 
    for (int i = 0; i < n; i++) 
        table[i][0] = arr[i]; 
  
    // Build sparse table 
    for (int j = 1; j <= n; j++) 
        for (int i = 0; i <= n - (1 << j); i++) 
            table[i][j] = __gcd(table[i][j - 1], 
                    table[i + (1 << (j - 1))][j - 1]); 
} 
  
// Returns GCD of arr[L..R] 
int query(int L, int R) 
{ 
    // Find highest power of 2 that is smaller 
    // than or equal to count of elements in given 
    // range.For [2, 10], j = 3 
    int j = (int)log2(R - L + 1); 
  
    // Compute GCD of last 2^j elements with first 
    // 2^j elements in range. 
    // For [2, 10], we find GCD of arr[lookup[0][3]] and 
    // arr[lookup[3][3]], 
    return __gcd(table[L][j], table[R - (1 << j) + 1][j]); 
} 
  
// Driver program 
int main() 
{ 
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    int a[] = { 7, 2, 3, 0, 5, 10, 3, 12, 18 }; 
    int n = sizeof(a) / sizeof(a[0]); 
    buildSparseTable(a, n); 
    cout << query(0, 2) << endl; 
    cout << query(1, 3) << endl; 
    cout << query(4, 5) << endl; 
    return 0; 
} 