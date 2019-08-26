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

const int N  = 123456;

int tree[4*N];
int lazy[4*N];
int arr[N];


void build(int s,int e,int index){
    if(s == e){
        tree[index] = arr[s];
        return ;
    }
    int mid = (s+e) >> 1;
    build(s,mid,2*index);
    build(mid+1,e,2*index+1);
    tree[index] = tree[2*index] + tree[2*index+1];
}

void update(int s,int e,int index,int pos,int val){
    if(pos < s || pos >e ) return ;
    if(s ==pos && pos == e){
        arr[pos] = val;
        tree[index] =val;
        return;
    }
    int mid = (s +e ) >> 1;
    update(s,mid,2*index,pos,val);
    update(mid+1,e,2*index+1,pos,val);
    tree[index] = tree[2*index] + tree[2*index+ 1];
}

int query(int s,int e,int index,int ss,int ee){
    if(s > ee || e < ss) return 0;
    if( s >=ss && e <=ee) return tree[index];
    int mid = (s+e) >>1;
    int l = query(s,mid,2*index,ss,ee);
    int r = query(mid+1,e,2*index+1,ss,ee);
    return l+r;
}

void updaterange(int s,int e,int index,int ss,int ee,int val){
    if(lazy[index] != 0){
        tree[index] += (e -s  +1) * lazy[index];
        if(s!=e){
            lazy[2*index] += lazy[index];
            lazy[2*index  + 1] += lazy[index];
        }
        lazy[index] = 0;
    }
    if( s > ee || e < ss) return ;
    if(s >= ss && e <=ee ) {
        
        tree[index] += (e -s + 1)* val;
        if(s!=e){
            lazy[2*index] += val;
            lazy[2*index+1] += val;
        }
        return;
    }
    int mid = (s +e ) >> 1;
    updaterange(s,mid,2*index,ss,ee,val);
    updaterange(mid+1,e,2*index+1,ss,ee,val);
    tree[index] = tree[2*index] + tree[2*index + 1];
}

int queryrange(int s,int e,int index,int ss,int ee){
    if(s > ee || e < ss)  return 0;
    if(lazy[index] != 0){
        tree[index] += (e -s + 1) *lazy[index];
        if(s!=e){
            lazy[2*index] += lazy[index];
            lazy[2*index +1] += lazy[index];
        }
        lazy[index]= 0;
    }
    if(s >=ss && e <= ee) {
        return tree[index];
    }
    int mid = (s+e) >> 1;
    int l = queryrange(s,mid,2*index,ss,ee);
    int r = queryrange(mid+1,e,2*index+1,ss,ee);
    return l+r;
}
            
            
int main(){
    
    int n;
    cin >> n;
    for(int i=0;i<n;i++) cin >> arr[i];
    int s = 0;
    int e = n-1;
    int index= 1 ;
    
    build(s,e,index);
    
    for(int i=0;i<4*n;i++){
        cout << tree[i] << " ";
    }cout << endl;
    updaterange(s,e,index,0,3,4);
    for(int i=0;i<4*n;i++){
        cout << tree[i] << " ";
    }cout << endl;
    for(int i=0;i<4*n;i++){
        cout << lazy[i] << " ";
    }cout << endl;
    cout << queryrange(s,e,index,0,3) << endl;
    updaterange(s,e,index,0,1,4);
    cout << queryrange(s,e,index,0,3) << endl;

    return 0;
}