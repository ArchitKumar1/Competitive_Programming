#include<bits/stdc++.h>
#pragma optimize("O3","-ofast")
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

LL GetCeilIndex(LL arr[], vector<LL>& T, LL l, LL r,LL key) { 
    while (r - l > 1) { 
        LL m = l + (r - l) / 2; 
        if (arr[T[m]] >= key) 
            r = m; 
        else
            l = m; 
    } 
    return r; 
} 


LL LongestIncreasingSubsequence(LL arr[], LL n) 
{ 
    vector<LL> tailIndices(n, 0); // Initialized with 0 
    vector<LL> prevIndices(n, -1); // initialized with -1 
  
    LL len = 1; // it will always poLL to empty location 
    for (LL i = 1; i < n; i++) { 
        if (arr[i] < arr[tailIndices[0]]) { 
            // new smallest value 
            tailIndices[0] = i; 
        } 
        else if (arr[i] > arr[tailIndices[len - 1]]) { 
            // arr[i] wants to extend largest subsequence 
            prevIndices[i] = tailIndices[len - 1]; 
            tailIndices[len++] = i; 
        } 
        else { 
            // arr[i] wants to be a potential condidate of 
            // future subsequence 
            // It will replace ceil value in tailIndices 
            LL pos = GetCeilIndex(arr, tailIndices, -1,len - 1, arr[i]); 
  
            prevIndices[i] = tailIndices[pos - 1]; 
            tailIndices[pos] = i; 
        } 
    } 
    return n-len; 
} 

int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    TC{

        LL n;
        cin >> n;
        LL arr[n];
        forn(i,n) cin >> arr[i];
        cout << LongestIncreasingSubsequence(arr,n) << endl;
    }

    
}