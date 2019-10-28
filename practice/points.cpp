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


////////////////////////////

struct point{
    double x,y;
    bool operator<(const point&b) const{
        return x < b.x;
    }
    point operator-(const point &b) {
        return {x-b.x,y-b.y};
    }
    point operator+(const point&b) {
        return {x+b.x,y+b.y};
    }
};

double dot(const point &a,const point&b){
    return (a.x*b.x + a.y*b.y);
}
double mag(const point&a){
    return pow(dot(a,a),.5);
}
double dotangle(const point &a,const point&b){
    return dot(a,b)/(mag(a)*mag(b));
}
ostream& operator<<(ostream &os,const point &a){
    return os << "[" << a.x <<"," << a.y<<"] ";
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    int n;
    cin >> n;
    vector<point> all(n);
     map<pair<double,double>,int> m1;
    
    forn(i,n){
        cin >> all[i].x >> all[i].y;
        m1[{all[i].x,all[i].y}] = 1;
    }
   
    int sum = 0;
    forn(i,n){
        for(int j = i+1;j<n;j++){
            for(int k = j+1;k<n;k++){
                if(i == j || k == j || i == k) continue;
                
                point x = all[i] - all[j];
                point y = all[k] - all[j];
                point z = x+y+all[j];
                if(dot(x,y) == 0 && m1[{z.x,z.y}] == 1)sum++; 

                x = all[k] - all[i];
                y = all[j] - all[i];
                z = x+y+all[i];
                if(dot(x,y) == 0 && m1[{z.x,z.y}] == 1)sum++;

                x = all[i] - all[k];
                y = all[j] - all[k];
                z = x+y+all[k];
                if(dot(x,y) == 0 && m1[{z.x,z.y}] == 1)sum++;
            }
        }
    }
    cout << sum/4 << endl;
 

    
}




