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

#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////
struct point{
    double x,y;
    //point(double x,double y) : x(x),y(y){};
    
    point operator-(const point &b){
        return {x-b.x,y-b.y};
    }
    point operator+(const point &b){
        return {x+b.x,y+b.y};
    }
    double operator*(const point &b){
        return (x*b.x + y+b.y);
    }
    static double mag(const point &a){
        return pow(a.x*a.x + a.y*a.y,0.5);
    }
    static double dotangle(point a,point b){
        return (a*b/point::mag(a)*point::mag(b));
    }
};

bool operator<(const point &a,const point &b){
    return a.x < b.x;
}
ostream& operator<<(ostream& os,const point &a){
    return os << "(" << a.x <<","<<a.y<<") ";
}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    cout<< setprecision(3);
    vector<point> all;
    map<point,int> m1;
    int n;
    cin >> n;
    all.resize(n);
    forn(i,n){
        cin >> all[i].x >> all[i].y;
        m1[all[i]] = 1;
    }
    //sort(ALL(all));
    int tcnt = 0;
    
    int cnt = 0 ;
    int scnt = 0;
    for(int i=0;i<n;i++){
        for(int j =0;j<n;j++){
            for(int k = 0;k<n;k++){
                
                if(i == j || k == j || i == k) continue;
                tcnt++;
                point a = all[i];
                point b = all[j];
                point c = all[k];
                //trace(i,j,k);
                if(point::dotangle(c-a,b-a) == 1 && m1[c+b-a] == 1)cnt++;
                if(point::dotangle(c-b,a-b) == 1 && m1[c-b+a] == 1)cnt++;
                if(point::dotangle(c-b,a-b) == 1 && m1[b-c+a] == 1)cnt++;
                //trace(i,j,k,cnt);
            }
        }
    }
    trace(tcnt);
    cout << cnt<< " "  << scnt/4 ;
}




