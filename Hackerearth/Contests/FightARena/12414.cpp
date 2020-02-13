#include<bits/stdc++.h>
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){return os<<"("<<P.first<<","<<P.second<<")";}

#ifndef ONLINE_JUDGE
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
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<LL> VL;
typedef vector<VL> VLL;
typedef pair<LL,LL>PLL;
typedef vector<PLL> VPLL;

int mod = pow(10,9) +7;


template <int MOD_> struct modnum {
	static constexpr int MOD = MOD_;
private:
	using ll = long long;
	int v;
	static int minv(int a, int m) {a %= m;assert(a);return a == 1 ? 1 : int(m - ll(minv(m, a)) * ll(m) / a);}
public:
	modnum() : v(0) {}
	modnum(ll v_) : v(int(v_ % MOD)) { if (v < 0) v += MOD; }
	explicit operator int() const { return v; }
	friend std::ostream& operator << (std::ostream& out, const modnum& n) { return out << int(n); }
	friend std::istream& operator >> (std::istream& in, modnum& n) { ll v_; in >> v_; n = modnum(v_); return in; }
 
	friend bool operator == (const modnum& a, const modnum& b) { return a.v == b.v; }
	friend bool operator != (const modnum& a, const modnum& b) { return a.v != b.v; }
 
	modnum inv() const {modnum res;res.v = minv(v, MOD);return res;}
	modnum neg() const {modnum res;res.v = v ? MOD-v : 0;return res;}
    modnum operator- () const {return neg();}
	modnum operator+ () const {return modnum(*this);}
	modnum& operator ++ () {v ++;if (v == MOD) v = 0;return *this;}
	modnum& operator -- () {if (v == 0) v = MOD;v --;return *this;}
	modnum& operator += (const modnum& o) {v += o.v;if (v >= MOD) v -= MOD;return *this;}
	modnum& operator -= (const modnum& o) {v -= o.v;if (v < 0) v += MOD;return *this;}
	modnum& operator *= (const modnum& o) {v = int(ll(v) * ll(o.v) % MOD);return *this;}
	modnum& operator /= (const modnum& o) {return *this *= o.inv();}
 
	friend modnum operator ++ (modnum& a, int) { modnum r = a; ++a; return r; }
	friend modnum operator -- (modnum& a, int) { modnum r = a; --a; return r; }
	friend modnum operator + (const modnum& a, const modnum& b) { return modnum(a) += b; }
	friend modnum operator - (const modnum& a, const modnum& b) { return modnum(a) -= b; }
	friend modnum operator * (const modnum& a, const modnum& b) { return modnum(a) *= b; }
	friend modnum operator / (const modnum& a, const modnum& b) { return modnum(a) /= b; }
};
using num = modnum<int(1e9)+7>;

template <typename T,typename U>void add_mod(T &a, U b){a = (LL)a+b;a = a%mod;}
template <typename T,typename U>void mul_mod(T &a, U b){a = ((LL)a*b)%mod;}
template <typename T> T add_mod(vector<T> v){LL sum=0; for(T x : v) sum = (sum + x)%mod;return (T)sum;}
template <typename T> T mul_mod(vector<T> v){ LL sum = 0;for(T x : v)sum = (sum * x)%mod;return (T)sum;}

int pow_mod(int a,int b,int m = mod){
    LL res = 1;
    while(b){
        if(b&1)res = ((LL)res*a)%mod;
        a = ((LL)a*a)%mod;
        b>>=1;
    }
    return res;
}

VI fact,inv_fact;

void calc_fact(int n,int mod){
    fact.assign(n+1,1);
    inv_fact.assign(n+1,1);
    for(int i=1;i<=n;i++) fact[i] = ((LL)fact[i-1]*i)%mod;
    for(int i=0;i<=n;i++) inv_fact[i] = pow_mod(fact[i],mod-2,mod);
}

const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

//-----------------------------------------------------------------------------



const LL N  = 123456;
vector<vector<LL>> G(N);
vector<LL> start(N),endd(N),val(N,0);

LL treesum[4*N][32][2],treexorsum[4*N][32][2];
LL lazyor[4*N][32],lazyand[4*N][32],lazyxor[4*N][32];

LL A[N];
LL timer = -1;

void build1(LL s,LL e,LL index,pos){
    if(s == e){
        treesum[index][pos] = A[s];
        return ;
    }
    LL mid = (s+e) >> 1;
    build1(s,mid,2*index);
    build1(mid+1,e,2*index+1);
    treesum[index][pos] = treesum[2*index] + treesum[2*index+1];
}

void build2(LL s,LL e,LL index){
    if(s == e){
        treexor[index] = A[s];
        return ;
    }
    LL mid = (s+e) >> 1;
    build1(s,mid,2*index);
    build1(mid+1,e,2*index+1);
    treexor[index] = treexor[2*index] ^ treexor[2*index+1];
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
            //trace(start[l],endd[l],start[r],endd[r]);
            //trace(fans1,fans2);
            cout << (fans1 ^ fans2) << endl;
        }
    }
    

    return 0;
}