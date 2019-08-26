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

const int mod = 1000 * 1000 * 1000 + 7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

/////////////////////////////
const int N = 5e6 +100;
LL arr[N];
LL tree[4 * N];
LL tree2[4 * N];

void mul(LL a[2][2],LL b[2][2]){
    LL q = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    LL r = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    LL s = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    LL t = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    q %= mod;
    r %= mod;
    s %= mod;
    t %= mod;
    a[0][0] = q;
    a[0][1] = r;
    a[1][0] = s;
    a[1][1] = t;
}

LL fib(LL x){
    LL a = 1;
    LL b = 0;
    if(x == 0)
        return 0;
    if(x == 1)
        return 1;
    LL base[2][2] = {{1, 0}, {0, 1}};
    LL fibmat[2][2] = {{1, 1}, {1, 0}};
    while(x){
        if(x%2 == 1){
            mul(base, fibmat);
        }
        x >>= 1;
        mul(fibmat, fibmat);
    }
    return base[0][0];
}

void build(LL s,LL e,LL index){
    if(s == e){
        tree[index] =  tree[index] = arr[s];
    }
    else{  
        int mid = (s + e) / 2;
        build(s,mid,2*index);
        build(mid+1,e,2*index+1);
        tree[index] = tree[2*index] + tree[2*index+1];
    }
}


void update(LL s,int e, int index,int val,int pos){
    if(s > pos || e < pos) return;
    if(s == e){
        arr[pos] = val;
        tree[index] = val;
    }
    else{
        int mid = (s + e) / 2;
        update(s ,mid , 2 *index , val,pos);
        update(mid+1,e, 2* index + 1,val,pos);
        tree[index] = tree[2*index + 1] + tree[2*index];
    }
}

int query(int s,int e,int index, int ss,int ee){
    if(ee < s || ss > e){
        return 0;
    }
    if(ee >= e && ss <= s){
        return tree[index];
    }
    int mid = (s+e)/2;
    int a = query(s,mid,2*index,ss,ee);
    int b = query(mid+1,e,2*index +1,ss,ee);
    return a+b;
}

int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    
}