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
 
 
int main(){
 
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    
    int n;
    cin >> n;
    string all[n];
    forn(i,n) cin >> all[i];
    bool check[n];
    memset(check,0,sizeof(check));
    string ss[n][2];
    int maxcnt[n][3];
    memset(maxcnt,0,sizeof(maxcnt));
    forn(i,n){
        forn(j,all[i].size()){
            char c = all[i][j];
            int len = 1;
            while(all[i][j+1] == c && j < all[i].size()){
                j++;
                len++;
            }
            if(c == 'E'){
                maxcnt[i][0] = max(maxcnt[i][0],len);
            }
            if(c == 'S'){
                maxcnt[i][1] = max(maxcnt[i][1],len);
            }
            if(c == 'C'){
                maxcnt[i][2] = max(maxcnt[i][2],len);
            }
        }
    }
    forn(i,n){
        int e = 0,s = 0,c=0;
        for(char cc : all[i]){
            e += (cc == 'E');
            c += (cc == 'C');
            s += (cc == 'S');
        }
        if( s == 0 && e == 0) check[i] = 1;
        int j = 0;
        char cc = all[i][j];
        int len = 1;
        while(all[i][j+1] == cc && j < all[i].size()){
            len++;
            j++;
        }
       // trace(cc,len);
        if(cc == 'C') ss[i][0] = all[i].substr(0,len);
       // trace(ss[i][0]);
        j = all[i].size()-1;
        cc = all[i][j];
        len = 1;
        while(all[i][j-1] == cc && j>=0){
            len++;
            j--;
        }
        if(cc == 'C') ss[i][1] = all[i].substr(j,len);
        
    }
    int fans =0 ;
    forn(i,n){
        fans =max(fans,maxcnt[i][2]);
    }
    int sans = 0;
    int maxpre= 0 ;
    int maxsuffix = 0;
    int uans = 0;
     vector<pair<int,int>> temp;
    forn(i,n){
        if(check[i] == 1){
            sans += all[i].size();
            //cout << "h" << i << endl;
        }else{
            temp.PB({ss[i][0].size(),ss[i][1].size()});
        }
    }
    //trace(temp);
    sort(temp.begin(),temp.end(),[](pair<int,int> a,pair<int,int> b){ return max(a.F ,a.S) > max(b.F ,b.S);});
    if(temp.size() >= 1){
        sans = max(sans , sans + max(temp[0].F ,temp[0].S));
    }
    if(temp.size() >= 2){
        sans = max(sans , sans + max(temp[1].F ,temp[1].S));
    }
    cout << fans << " " << sans << endl;

   
   
    return 0;
}