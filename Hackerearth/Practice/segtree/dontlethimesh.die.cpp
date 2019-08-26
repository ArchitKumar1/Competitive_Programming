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

const int M = 100;
const int N = 1e4 + 100;
bitset<M> tree[4*N];
int arr[N];
int tree2[4 * N];


bitset<M> base;
void build(int s,int e,int index){
    if(s == e){
        bitset<M> temp;
        tree[index] = temp.set(arr[s]);
        tree2[index] = arr[s];
        return ;
    }
    int mid = (s+e) >> 1;
    build(s,mid,2*index);
    build(mid+1,e,2*index+1);
    tree[index] = tree[2*index] | tree[2*index+1];
    tree2[index] = max(tree2[2*index] , tree2[2*index+1]);
}


bitset<M> query(int s,int e,int index,int ss,int ee){
    if(s > ee || e < ss) return base;
    if( s >=ss && e <=ee) return tree[index];
    int mid = (s+e) >>1;
    bitset<M> l = query(s,mid,2*index,ss,ee);
    bitset<M> r = query(mid+1,e,2*index+1,ss,ee);
    return l|r;
}        

int query2(int s,int e,int index,int ss,int ee){
    if(s > ee || e < ss) return 0;
    if( s >=ss && e <=ee) return tree2[index];
    int mid = (s+e) >>1;
    int l = query2(s,mid,2*index,ss,ee);
    int r = query2(mid+1,e,2*index+1,ss,ee);
    return max(l, r);
}           
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    int s = 0;
    int e = n-1;
    int index= 1 ;
    build(s,e,index);

    int q;
    cin >> q;
    while(q--){
        int l, r;
        cin >> l >> r;
        int aa = query(s, e, index, l, r).count();
        int bb = query2(s, e, index, l, r);
        cout << bb - aa << endl;
    }
    return 0;
}