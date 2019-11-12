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


struct point{
    double x,y;
};
double dist(const point &a,const point &b){
    return sqrt((a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y));
}
int main(){
    FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif   
     
     cout.precision(10);
     cout << fixed;
    int t;
    cin >> t;
    while(t--){
        point X;
        cin >> X.x >> X.y;
        int n,m,k;
        cin >> n >> m >> k;
        vector<point> vn(n),vm(m),vk(k);
        for(int i=0;i<n;i++){
            cin >> vn[i].x >> vn[i].y;
        }
        for(int i=0;i<m;i++){
            cin >> vm[i].x >> vm[i].y;
        }
        for(int i=0;i<k;i++){
            cin >> vk[i].x >> vk[i].y;
        }
        
        vector<double> dn1(n,inf),dn2(n,inf),dm1(m,inf),dm2(m,inf),fans(k,inf);

        for(int i=0;i<n;i++){
            dn1[i] = min(dn1[i],dist(X,vn[i]));
        }
        for(int i=0;i<m;i++){
            dm1[i] = min(dm1[i],dist(X,vm[i]));
        }
        for(int i=0;i<n;i++){
            for(int j = 0;j<m;j++){
                double d = dn1[i] + dist(vn[i],vm[j]);
                if(dm2[j] > d) dm2[j] = d;
            }
        }
        for(int i=0;i<m;i++){
            for(int j = 0;j<n;j++){
                double d = dm1[i] + dist(vm[i],vn[j]);
                if(dn2[j] > d) dn2[j] = d;
            }
        }

        for(int i=0;i<m;i++){
            for(int j = 0;j<k;j++){
                double d = dm2[i] + dist(vm[i],vk[j]);
                if(fans[j] > d) fans[j] = d;
            }
        }

        for(int i=0;i<n;i++){
            for(int j = 0;j<k;j++){
                double d = dn2[i] + dist(vn[i],vk[j]);
                if(fans[j] > d) fans[j] = d;
            }
        }
        cout << *min_element(fans.begin(),fans.end()) << "\n";


    }
#ifndef ONLINE_JUDGE
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
}