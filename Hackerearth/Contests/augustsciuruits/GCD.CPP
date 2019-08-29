#include<bits/stdc++.h>
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

const LL N = 2e5 + 100;
LL arr[N],tree[N];

void build(LL s,LL e,LL index){
    if(s > e ) return ;
    if(s == e){
        tree[index] = arr[s];
        return;
    } 
    LL mid = (s+e)/2;
    build(s,mid,2*index);
    build(mid+1,e,2*index  +1);
    tree[index] = __gcd(tree[2*index],tree[2*index + 1]);
}

LL query(LL s,LL e,LL ss,LL ee,LL index){
    if(s > ee || e < ss) return 0 ;
    if(s >= ss && e <= ee) return tree[index];
    LL mid = (s+e)/2;
    return __gcd(query(s,mid,ss,ee,2*index),query(mid+1,e,ss,ee,2*index+1));
}


int main(){
    FASTIO
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    LL n;
    cin >> n;
    LL q;
    cin >> q;

    forn(i,n) cin >> arr[i];
    LL s = 0;
    LL e = n-1;
    LL index = 1;
    build(s,e,index);


    while(q--){
        LL l,r;
        cin >> l >> r;
        --l;--r;
        LL ans =0;
        for(LL i=l;i<=r;i++){
            for(LL j = i;j<=r;j++){
                ans += query(s,e,i,j,index);
            }
        }
        cout << ans << endl;
    }
}