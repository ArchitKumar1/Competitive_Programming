#include<bits/stdc++.h>
#pragma optimize("O3","-ofast")
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
#define ALL(x) x.begin(),x.end()
#define LL long long int
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define endl "\n"
#define l() cout << endl;
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)

const int mod = pow(10,9)+7;
const double inf = 1e18;
const LL linf = 2e18;
const double eps = 1e-9;

//////////////////////////////////////////////


const int N  = 1e5+100;
LL arr[N],bits[4*N][40];

LL pow(LL a,LL b,LL c){
    a = a%c;
    LL res = 1;
    while(b){
      
        if(b&1) res = (res*a)%c;
        a = (a*a)%c;
        b>>=1;
    }
    return res;
}
LL inv_2 = pow(2,mod-2,mod);
LL inv_6 = pow(6,mod-2,mod);
LL add(LL a,LL b ){
    return  (a%mod + b%mod)%mod;
}
LL mul(LL a,LL b){
    return ((LL) a%mod * b%mod)%mod;
}
LL nc2(LL n){
    return mul(mul(n,n-1),inv_2);
}
LL nc3(LL n){
    return mul(mul(mul(n,n-1),n-2),inv_6);
}
void build(int s,int e,int index){
    if(s == e){
        for(int i=0;i<40;i++){
            bits[index][i] = (arr[s] & (1LL << i)) != 0;
        }
        return;
    }
    int m = (s+e)>>1;
    build(s,m,2*index);
    build(m+1,e,2*index+1);
    for(int i=0;i<40;i++){
        bits[index][i] = bits[2*index][i] + bits[2*index+1][i]; 
    }
}
vector<int> base(40,0);

int query(int index, int s,int e,int ss,int ee,int pos){
    if(s > ee || e  < ss) return 0;
    if(s >=ss && e<=ee) {
        return bits[index][pos];
    }
    int m  = (s+e)>>1;
    return query(2*index,s,m,ss,ee,pos)+query(2*index+1,m+1,e,ss,ee,pos);
}

int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
    FASTIO
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        cin >> arr[i];

    }
    int s = 0;
    int e = n-1;
    int index = 1;

    build(s,e,index);
    int q,dummy;
    cin >> q >> dummy;
    forn(j,q){
        int l,r;
        cin >> l >> r;
        --l;--r;
        vector<int> fans(40,0); 
        // cout << fans << endl;
        LL uans = 0;
        for(int i=0;i<40;i++){
            
            fans[i] =query(index,s,e,l,r,i); 
           // cout << j << " "<< i<< " " << fans[i] << endl;
            LL nzeros = r-l+1 - fans[i];
            uans += mul(mul(pow(2LL,i),fans[i]),nc2(nzeros));
            uans %= mod;
            uans += mul(pow(2LL,i),nc3(fans[i]));
            uans %= mod; 
            
        }
        cout << uans << endl;
    }
    // for(int i=0;i<8;i++){
    //     for(int j = 0;j<40;j++){
    //         cout << bits[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    

}