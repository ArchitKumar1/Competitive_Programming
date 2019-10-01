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
 
const int mod = pow(10,9) +9;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;
 
 
/////////////////////////////
 
const LL N = 2e5;
LL arr[N];
vector<LL> tree(4*N,0),tree2(4*N,0);
void build(LL s,LL e,LL index){
    if(s == e){
        tree[index] =  arr[s]%2 == 1 ? arr[s] :0 ;
        tree2[index] =  arr[s]%2 == 0 ? arr[s] : 0;
        return;
    }
    else{  
        LL mid = (s + e) / 2;
        build(s,mid,2*index);
        build(mid+1,e,2*index+1);
        tree[index] = max(tree[2*index],tree[2*index+1]);
        tree2[index] = max(tree2[2*index],tree2[2*index+1]);
    }
}


void update(LL s,LL e, LL index,LL val,LL pos){
    if(s > pos || e < pos) return;
    if(s == e){
        tree[index] =  arr[s]%2 == 0 ? 0 : arr[s];
        tree2[index] =  arr[s]%2 == 1 ? 0 : arr[s];
    }
    else{
        LL mid = (s + e) / 2;
        update(s ,mid , 2 *index , val,pos);
        update(mid+1,e, 2* index + 1,val,pos);
        tree[index] = max(tree[2*index],tree[2*index+1]);
        tree2[index] = max(tree2[2*index],tree2[2*index+1]);
    }
}

LL query1(LL s,LL e,LL index, LL ss,LL ee){
    if(s > ee || e < ss){
        return 0;
    }
    if(s >=ss && e <= ee){
        return tree[index];
    }
    LL mid = (s+e)/2;
    LL a = query1(s,mid,2*index,ss,ee);
    LL b = query1(mid+1,e,2*index +1,ss,ee);
    return a+b;
}
LL query2(LL s,LL e,LL index, LL ss,LL ee){
    if(s > ee || e < ss){
        return 0;
    }
    if(s >=ss && e <= ee){
        return tree2[index];
    }
    LL mid = (s+e)/2;
    LL a = query2(s,mid,2*index,ss,ee);
    LL b = query2(mid+1,e,2*index +1,ss,ee);
    return a+b;
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
    LL s = 0;
    LL index = 1;
    LL e = n-1;
    forn(i,n) cin >> arr[i];
    build(s,e,index);

    while(q--){
        LL x;
        cin >> x;
        if(x == 1){
            LL pos,val;
            --pos;
            cin >> pos >> val;
            update(s,e,index,val,pos);
        }
        if(x == 2){
            LL l,r;
            cin >> l >> r;
            --l;--r;
            LL ans = query2(s,e,index,l,r);
            if(ans %2 == 1){
                cout << "DNE" << endl;
            }else{
                cout << ans << endl;
            }
        }
        if(x ==3){
            LL l,r;
            cin >> l >> r;
            --l;--r;
            LL ans = query1(s,e,index,l,r);
            if(ans %2 == 0 ){
                cout << "DNE" << endl;
            }else{
                cout << ans << endl;
            }
        }
    }

    cout << endl;
}