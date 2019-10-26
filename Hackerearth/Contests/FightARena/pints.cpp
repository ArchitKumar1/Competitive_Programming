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

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////
const int N = 123456;
const int K = 26;
int BIT[N][K];


    
void update(int x,int val,int pos){
    
    for(;x<N;x += x&-x){
        BIT[x][pos]+= val;
    }
}   
int query(int x,int pos){
    int sum = 0;
    for(;x>0 ;x -= x&-x){
        sum += BIT[x][pos];
    }
    return sum;
}


int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    int n;
    int q;
    cin >> n >> q;
    string s;
    cin >> s;
    
    for(int i=0;i<n;i++){
        update(i+1,1,s[i]-'a');
    }
    while(q--){
        int x ;
        cin >> x;
        if(x == 2 ){
            int l,r;
            cin >> l >> r;
            int len = l-r+1;
            int odd =0 ;
            forn(k,26){
                if((query(r,k) - query(l-1,k))%2 == 1)odd++;
            }
            if(odd<=1){
                cout << "yes\n";
            }else{
                cout << "no\n";
            }
        }else{
            int l;
            char c;
            cin >> l >> c;
            update(l,1,c-'a');
            update(l,-1,s[l-1]-'a');
            s[l-1] = c;
        }
    }


    
}




