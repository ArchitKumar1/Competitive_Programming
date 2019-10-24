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

const int N = 10;
int M;
vector<string> cross(10);
vector<string> allwords;
int dx[4] = {0,1,0,-1};
int dy[4] ={1,0,-1,0};

inline bool safe(int i,int j){
    return i>=0 && i<M && j<M && j>=0;
}
int getlen(int i,int j,int dir,vector<string> &cross){
    int cnt = 1;
    while(safe(i+dx[dir],j +dy[dir]) && cross[i][j] == '-'){
        cnt++;
        i = i + dx[dir];
        j = j + dy[dir];
    }
    return cnt;
}
int checknode(int i,int j,vector<string>&cross){
    vector<int>temp(4);
    forn(k,4){
        temp[k] = getlen(i,j,k,cross);
    }
    sort(ALL(temp));
    return (temp[0] == 1 && temp[1] == 0 && temp[2] ==0 );
}
void solve(int curr,vector<string> cross){
    if(curr== M){
        cout << cross << endl;
        return;
    }
    forn(i,N){
        forn(j,N){
            if(cross[i][j] == '-'){
                    if(checknode(i,j,cross)){
                    int posslen = INT_MIN;
                    int dirtogo;
                    forn(k,4){
                        posslen =getlen(i,j,k,cross);
                        
                    }
                    if(posslen = allwords[curr].size()){

                    }
                }
            }
        }
    }
    
}

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    for(int i=0;i<N;i++){
        cin >> cross[i];
    }     
    string words;
    getline(cin,words);
    
    
    string temp ="";
    for(char c : words){
        if(c!=';'){
            temp+= c;
        }else{
            allwords.PB(temp);
            temp ="";
        }
    }
    if(temp!=""){
        allwords.PB(temp);
    }
    M = allwords.size();

    solve(0,cross);
    return 0;
    
}




