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
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


////////////////////////////

const int N = 123456;
int arr[N];


void merge(int s,int m,int e){
    int p = s;
    int q = m+1;
    int temp[e-s+1];
    int k = 0;
    while(p <=m || q <=e){
        if(p > m){
            temp[k++] = arr[q++];
        }else if(q > e){
            temp[k++] = arr[p++];
        }else if(arr[p] > arr[q]){
            temp[k++] = arr[q++];
        }else{
            temp[k++] = arr[p++];
        }
    }
    forn(i,e-s+1){
        arr[s+i] = temp[i];
    }
}
void mergesort(int s,int e){
    if(s< e){
        int mid = (s+e)>>1;
        mergesort(s,mid);
        mergesort(mid+1,e);
        merge(s,mid,e);
    }
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
   
    int n;
    cin >> n;
    forn(i,n) cin >> arr[i];
    mergesort(0,n-1);
    forn(i,n){
        cout << arr[i] << " ";
    }
    
    
}




