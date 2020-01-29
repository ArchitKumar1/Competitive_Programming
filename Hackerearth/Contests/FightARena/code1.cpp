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

bool isprime(int x){
    if(x == 1 || x == 0){
        return 0;
    }
    if(x == 2) return 1;
    bool ok = 1;
    for(int i =2;i*i<=x;i++){
        if(x%i == 0) return 0;
    }
    return 1;
}

int main(){
FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif
    
    
    TC{
        int n;
        cin >> n;
        int num = 0;
        for(int  i = 1;i*i<=n;i++){
            if(n%i == 0){
                num+=1;
                if(n/i != i){
                    num+=1;
                }
            }
        }
        if(isprime(num)){
            cout<< "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }

}