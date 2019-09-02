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

/////////////////////////////

const LL N  = 123456;
vector<vector<LL>> G(N);
vector<LL> start(N),endd(N),val(N,0);

LL tree[4*N];
LL lazy[4*N];
LL A[N];
LL timer = -1;

void dfs(LL s,LL par){
    ++timer;
    start[s] = timer;
    for(LL c : G[s]){
        if(c !=par){
            dfs(c,s);
        }
    }
    endd[s] =timer;
}

void build(LL s,LL e,LL index){
    if(s == e){
        tree[index] = A[s];
        return ;
    }
    LL mid = (s+e) >> 1;
    build(s,mid,2*index);
    build(mid+1,e,2*index+1);
    tree[index] = tree[2*index] + tree[2*index+1];
}

void updaterange(LL s,LL e,LL index,LL ss,LL ee,LL val){
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
    LL mid = (s +e ) >> 1;
    updaterange(s,mid,2*index,ss,ee,val);
    updaterange(mid+1,e,2*index+1,ss,ee,val);
    tree[index] = tree[2*index] + tree[2*index + 1];
}

LL queryrange(LL s,LL e,LL index,LL ss,LL ee){
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
    LL mid = (s+e) >> 1;
    LL l = queryrange(s,mid,2*index,ss,ee);
    LL r = queryrange(mid+1,e,2*index+1,ss,ee);
    return l+r;
}
            
            
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    LL n;
    cin >> n;
    LL q;
    cin >> q;

    for(LL i=0;i<n;i++) cin >> val[i];

    for(LL i=0;i<n-1;i++){
        LL x,y;
        cin >> x >> y;
        --x;--y;
        G[x].PB(y);
        G[y].PB(x);
    }
    dfs(0,-1);
    for(LL i=0;i<n;i++){
        A[start[i]] = val[i];
    }
    LL s = 0;
    LL e = n-1;
    LL index= 1 ;
    // for(LL i=0;i<n;i++){
    //     trace(i,val[i]);
    // }
    // for(LL i=0;i<n;i++){
    //     trace(i,start[i],endd[i]);
    // }
    build(s,e,index);
    while(q--){
        LL x,l,r;
        cin >> x >> l >> r;
        
        if(x == 1){
            l--;
            LL ans = queryrange(s,e,index,start[l],endd[l]);
            if(ans % 2== 0){
                updaterange(s,e,index,start[l],endd[l],r);
            }else{
                updaterange(s,e,index,start[l],endd[l],1);
            }
        }else{
            l--;r--;
            LL fans1 = queryrange(s,e,index,start[l],endd[l]);
            LL fans2 =  queryrange(s,e,index,start[r],endd[r]);
            trace(start[l],endd[l],start[r],endd[r]);
            trace(fans1,fans2);
            cout << (fans1 ^ fans2) << endl;
        }
    }

    return 0;
}