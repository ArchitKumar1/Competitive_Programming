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




void merge(int *arr,int s,int mid,int e){
    int temp[e-s+1];
    int a = s;
    int b = mid+1;
    int k = 0;
    while(1){
        if(a > mid && b > e ) break;
        if(a > mid) temp[k++] = arr[b++];
        else if(b > e) temp[k++] = arr[a++];
        else if(arr[a] > arr[b]) temp[k++] = arr[b++];
        else temp[k++] = arr[a++];
    }
    for(int i=0;i<k;i++){
        arr[s + i] =temp[i];
    }
    
}
void mergesort(int *arr,int s,int e){
    if(s < e){
        int mid = (s+e) >> 1;
        mergesort(arr,s,mid);
        mergesort(arr,mid+1,e);
        merge(arr,s,mid,e);
    }
}
void insertionsort(int *arr,int n){
    for(int i=1;i<n;i++){
       int k = i;
       int j = i-1;
       while(j>=0 && arr[j] > arr[k]){
           swap(arr[j--],arr[k--]);
       }
    }
}
void bubblesort(int *arr, int n){
    for(int i=0;i<n;i++){
        for(int j= i+1;j<n;j++){
            if(arr[i]>arr[j]) swap(arr[i],arr[j]);
        }
    }
}
void selectionsort(int *arr,int n){
    for(int i=0;i<n;i++){
        int index = i;
        int ans = arr[i];
        for(int j = i+1;j<n;j++){
            if(arr[j]< ans){
                ans = arr[j];
                index = j;
            }
        }
        swap(arr[i],arr[index]);
    }
}
        
int main(){
FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    insertionsort(arr,n);
    for(int x : arr) cout << x << " ";

}