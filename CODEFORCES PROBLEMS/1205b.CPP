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

const int mod = pow(10,9)+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

/////////////////////////////


const int N = 123456;
map<int,int> par,size;

void make(int i){
    par[i] = i;
    size[i] =  1;
}
int find(int v){
    if(v == par[v]){
        return v;
    }else{
        return par[v] = find(par[v]);
    }
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    
    if(a!=b){
        if(size[a] < size[b]) swap(a,b);
        par[b] =a;
        size[a] += size[b];
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    FASTIO
    int n;
    cin >> n;
    int len = 64;
    int arr[n];
    
    forn(i,n) cin >>arr[i];
    for(int i=0;i<n+1;i++){
        make(arr[i]);
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<62;j++){
            if((arr[i] &(1 << j)) && (arr[i-1] &(1 << j))){
                merge(arr[i],arr[i-1]);
                //DEBUG2(arr[i],arr[i-1]);
            }
        }
    }
    map<int,int>m1;
    for(int i=0;i<n;i++){
        int p = find(arr[i]);
       // DEBUG2(p,size[p]);
        m1[p] = 1;
    }
    int ans = 0;
    int c = INT_MAX;
    for(auto x : m1){
        //DEBUG2(x.F,size[x.S]);
        c = min(c,size[x.F]);
    }
    cout <<c << endl;

}