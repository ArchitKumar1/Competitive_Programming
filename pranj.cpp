//Author - archit //
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

const LL N  = 1234567;
vector<vector<LL>> G(N);
vector<LL> start(N),endd(N),val(N,0);

LL tree[4*N];
LL lazy[4*N];
LL heavy[4*N];
LL A[N];
LL timer = -1;

int sumofFactors(int n) 
{ 
    int res = 1; 
    for (int i = 2; i <= sqrt(n); i++) 
    { 
        int curr_sum = 1; 
        int curr_term = 1; 
        while (n % i == 0) { 
            n = n / i; 
            curr_term *= i; 
            curr_sum += curr_term; 
        } 
        res *= curr_sum; 
    } 
    if (n >= 2) 
        res *= (1 + n); 
    return res; 
} 
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
        int factsum = sumofFactors(val[s]);
        heavy[index] = (factsum%3 == 0 ? 1 : 0); 
        return ;
    }
    LL mid = (s+e) >> 1;
    build(s,mid,2*index);
    build(mid+1,e,2*index+1);
    heavy[index] = heavy[2*index] + heavy[2*index+1];
}

void updaterange(LL s,LL e,LL index,LL ss,LL ee,LL value){
    if( s > ee || e < ss) return ;
    if(s == e){
        heavy[index] = sumofFactors(value)%3 == 0 ? 1 : 0;
        return;
    }
    LL mid = (s +e ) >> 1;
    updaterange(s,mid,2*index,ss,ee,value);
    updaterange(mid+1,e,2*index+1,ss,ee,value);
    heavy[index] = heavy[2*index] + heavy[2*index+1];
}

LL queryrange(LL s,LL e,LL index,LL ss,LL ee){
    if(s > ee || e < ss)  return 0;
    if(s >=ss && e <= ee) {
        return heavy[index];
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
    for(LL i=0;i<n-1;i++){
        LL x,y;
        cin >> x >> y;
        --x;--y;
        G[x].PB(y);
        G[y].PB(x);
    }
    for(LL i=0;i<n;i++) cin >> val[i];

    dfs(0,-1);
    for(LL i=0;i<n;i++){
        A[start[i]] = val[i];
    }

    LL s = 0;
    LL e = n-1;
    LL index= 1 ;
    build(s,e,index);
    while(q--){
        LL x,X,Y;
        cin >> x;
        if(x == 1){
            cin >> X >> Y;
            --X;
            updaterange(s,e,index,start[X],start[X],Y);
            
        }else{
            cin >> X;
            --X;
            cout <<  queryrange(s,e,index,start[X],endd[X]) << endl;
        }
    }
    // for(int i=0;i<4*n;i++){
    //     cout << heavy[i] << " ";
    // }
    // cout << endl;
    // for(int i=0;i<n;i++){
    //     trace(val[i],sumofFactors(val[i]));
    // }
    
// 5 5
// 1 2
// 1 3
// 3 4
// 3 5
// 16 8 17 3 18
// 2 1
// 2 3
// 1 3 7
// 2 1
// 2 3
    cout <<  queryrange(s,e,index,start[0],endd[0]) << endl;
    return 0;
}