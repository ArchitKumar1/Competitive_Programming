#include<bits/stdc++.h>
#pragma GCC optimize("O3","Ofast")
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){return os<<"("<<P.first<<","<<P.second<<")";}
#define DEBUG1(x) cout  << '>' << " " << #x << ':' << " " <<  x << endl;
#define DEBUG2(x,y) cout  << '>' << " " << #x << ':' << " " <<  x <<  " " << #y << ':' << " " <<  y <<endl;
#define DEBUG3(x,y,z) cout  << '>' << " " << #x << ':' << " " <<  x << " " << #y << ':' << " " <<  y <<" " << #z << ':' << " " <<  z << " " <<endl;
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

const int mod = 10*9+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

/////////////////////////////


void merge(int s,int mid,int e,int arr[]){
    int temp[e - s + 1];
    int p = s;
    int q = mid + 1;
    int k = e - s + 1;
    for(int i = 0; i < k;i++){
        if(p > mid) temp[i] = arr[q++];
        else if(q > e) temp[i] = arr[p++];
        else if(arr[p] > arr[q]) temp[i] = arr[q++];
        else temp[i] = arr[p++];
    }
    for(int i = 0; i < k;i++){
        arr[s + i] = temp[i];
    }
}

void mergesort(int s,int e,int arr[]){
    if(s < e){
        int mid = (s + e) / 2;
        mergesort(s, mid,arr);
        mergesort(mid + 1, e,arr);
        merge(s, mid, e,arr);
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++){
        cin >> arr[i];
    }
    mergesort(0, n - 1,arr);
    forn(i,n){
        cout << arr[i] << " ";
    }
}