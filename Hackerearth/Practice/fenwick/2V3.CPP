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
const int N = 223456;

int BIT0[N];
LL arr0[N];

int BIT1[N];
LL arr1[N];
void update0(int x,int val){

    for(;x<N;x+=x&-x){
        BIT0[x]+=val;
    }
}   
int query0(int x){
    int sum = 0;
    for(;x >0 ;x -= x&-x){
        sum += BIT0[x];
    }
    return sum;
}
void update1(int x,int val){

    for(;x<N;x+=x&-x){
        BIT1[x]+=val;
    }
}   
int query1(int x){
    int sum = 0;
    for(;x >0 ;x -= x&-x){
        sum += BIT1[x];
    }
    return sum;
}


int main(){
    FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    int n;
    cin >> n;
    string s;
    cin >> s;
    int q;
    cin >> q;
    int len = s.size();
    for(int i=0;i<len;i++){
        if(s[i] == '1'){
            if(i%2 == 0){
                update0(i+1,1);
            }else {
                update1(i+1,1);
            }
        }
    }
    while(q--){
        int x;
        cin >> x;
        if(x == 0){
            int l,r;
            cin >> l >> r;
            l++;r++;
            int even = query0(r) -query0(l-1);
            int odd =  query1(r) -query1(l-1);
            if((r-1)%2 == 1){
                swap(odd,even);
            }
            
            //trace(l-1,r-1,even,odd);
            int mod =(even%3 + odd%3 + odd%3)%3;
            cout << mod << endl;
        }else{
            //cout << s << endl;
            int l;
            cin >> l;
            l++;
            if(s[l-1] == '0'){
                if((l-1)%2 == 0){
                    update0(l,1);
                }else{
                    update1(l,1);
                }
                s[l-1] = '1';
            }
            //cout << s << endl;
        }
    }
    
}




