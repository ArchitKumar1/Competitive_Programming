#include<bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os,vector<T> V){
    os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){
    return os<<"("<<P.first<<","<<P.second<<")";
}

#ifndef ONLINE_JUDGE
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
    point(): x(0),y(0){};
    point(double x,double y): x(x),y(y){};
};
struct line{
    double m,c;
    line() : m(0),c(0){};
    line(point a,point b){
        (*this).m = (b.y - a.y)/(b.x - a.x);
        (*this).c = a.y - a.x * (*this).m;
    }
};


double get_y(double x,double y,line l){
     double ydown =  (x * l.m + l.c); 
     return y - ydown;
}


const int N = 123;

point left1[N];
point right1[N];
bool vis[N];
int main(){
    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif 
FASTIO  
    
    cout << setprecision(4);
    cout << fixed;
    double X;
    cin >> X;
    double Y = 1e9;
    int n;
    cin >> n;
    forn(i,n){
        cin >> left1[i].x >> left1[i].y >> right1[i].x >> right1[i].y;
    }
    bool ok = 1;
    double fans = 1;
    int t = 10;
    while(ok){
        vector<int> prob;
        forn(i,n){
            if(left1[i].x <= X && right1[i].x >=X  && vis[i]==0){
                prob.PB(i);
            }
        }
        trace(prob);
        if(prob.size() == 0){
            break;
        }
        
        double distance = INT_MAX;
        int max_p = 0;
        forn(i,prob.size()){
            line curr_line = line(left1[prob[i]],right1[prob[i]]);
            
           double  curr_dist = get_y(X,Y,curr_line);
           if(curr_dist < distance) {
               distance =curr_dist;
               max_p = prob[i]; 
           }
        }
        trace(distance,max_p);
        vis[max_p] = 1;
        if( right1[max_p].y <= 0  || left1[max_p].y <=0){
            line curr_line = line(left1[prob[max_p]],right1[prob[max_p]]);
            fans = -curr_line.c /curr_line.m;
            
            ok = 0;
            break;
        }
        point down;
        if(left1[max_p].y < right1[max_p].y){
            down = left1[max_p];
        }else{
            down = right1[max_p];
        }
        Y = down.y;
        X = down.x;
        trace(X,Y);

    }
    cout << (int)X << endl;



#ifndef ONLINE_JUDGE
    cerr << "Time: " << double(clock()) / CLOCKS_PER_SEC << '\n';
#endif
}