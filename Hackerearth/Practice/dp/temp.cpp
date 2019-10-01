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
 
const LL N = 1e7;
vector<LL> prime(N,1);
vector<LL> all;
void seive(){
    for(LL i =2;i*i<N;i++){
        if(prime[i] == 1){
            for(LL j=i*i;j<N;j+=i){
                prime[j] = 0;
            }
        }
    }
    for(LL i=2;i<N;i++){
        if(prime[i] == 1){
            all.PB(i);
        }
    }
}

vector<pair<LL,LL> > find(LL x){
    LL i = 0;
    vector<pair<LL,LL>> temp;
    while(all[i]*all[i]<=x){
        if(x%all[i] == 0){
            LL cnt = 1;
            x = x/all[i];
            while(x%all[i] == 0){
                x = x/all[i];
                cnt++;
            }
            temp.PB({all[i],cnt});
            
        }
        i++;
    }
    if(x!=1){
        temp.PB({x,1});
    }
    return temp;
}
map<vector<pair<LL,LL>>,LL> m1;

void solve(vector<LL> &every,vector<pair<LL,LL>>all,LL currfactor){
    if(m1[all] == 1) return;
    m1[all] = 1;
    LL n = all.size();
    if(currfactor == 1 || currfactor == 0) return ;
    every.PB(currfactor);
    //trace(all,currfactor);
    for(LL i=0;i<n;i++){
        if(all[i].second >0){
            currfactor/= all[i].first;
            all[i].second-=1;
            solve(every,all,currfactor);
            all[i].second+=1;
            currfactor*= all[i].first;
        }
    }
}
int main(){
 
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    seive();

    TC{
        LL a,b,k;
        cin >>  a >> b >> k;
        vector<pair<LL,LL>> x = find(a);
        vector<pair<LL,LL>> y = find(b);
        //trace(x,y);
        vector<LL> ex{1};
        vector<LL> ey{1};
        m1.clear();
        solve(ex,x,a);
        m1.clear();
        solve(ey,y,b);
        //trace(ex,ey);
        sort(ALL(ex));
        sort(ALL(ey));
        map<LL,LL> m2,m3;
        for(LL c : ex){
            m2[c] = 1;
        }
        for(LL d : ey){
            m3[d] = 1;
        }
        vector<LL> fans;
        for(LL c : ex){
            if(m3[c] == 1){
                fans.PB(c);
                m2[c] -=1;
            }
        }
        for(LL c : ey){
            if(m2[c] == 1){
                fans.PB(c);
                m3[c] -=1;
            }
        }
        sort(ALL(fans));
        //trace(fans);
        LL tans = 0;
        if(fans.size()>=k){
            cout << fans[fans.size()-k] << endl;
        }else{
            cout << "No crymeth today" << endl;
        }
    }
    
    
    return 0;
}