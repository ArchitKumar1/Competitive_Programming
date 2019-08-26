#include<bits/stdc++.h>
#pragma GCC optimize("O3","Ofast")
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){return os<<"("<<P.first<<","<<P.second<<")";}
#define DEBUG1(x) cout  << '>' << " " << #x << ':' << " " <<  x << endl;
#define DEBUG2(x,y) cout  << '>' << " " << #x << ':' << " " <<  x <<  " " << #y << ':' << " " <<  y <<endl;
#define DEBUG3(x,y,z) cout  << '>' << " " << #x << ':' << " " <<  x << " " << #y << ':' << " " <<  y <<" " << #z << ':' << " " <<  z << " " <<endl;
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

const int mod = pow(10,9)+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

void nope(){
    cout << "Wait, what?" << endl;
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    FASTIO;

    int n= 3;
    char g[n][n];
    int dcnt=0;
    int xcnt =0 ;
    int zcnt =0;
    forn(i,n)forn(j,n){
        cin >> g[i][j];
        if(g[i][j] == '.') dcnt++;
        if(g[i][j] == 'X') xcnt++;
        if(g[i][j] == 'O') zcnt++;
    }
    if(abs(xcnt - zcnt )>1){
        nope();
        return 0;
    }
    if(zcnt - xcnt >0){
        nope();
        return 0;
    }
    int tz =0,tx = 0;
    for(int i=0;i<n;i++){
        tz += g[i][0]=='O' && g[i][1]=='O' && g[i][2]=='O';
        tx += g[i][0]=='X' && g[i][1]=='X' && g[i][2]=='X';
    }
    for(int j=0;j<n;j++){
        tz += g[0][j]=='O' && g[1][j]=='O' && g[2][j]=='O';
        tx += g[0][j]=='X' && g[1][j]=='X' && g[2][j]=='X';
    }
    
    tz += g[0][0]=='O' && g[1][1]=='O' && g[2][2]=='O';
    tx += g[0][0]=='X' && g[1][1]=='X' && g[2][2]=='X';
    tz += g[0][2]=='O' && g[1][1]=='O' && g[2][0]=='O';
    tx += g[0][2]=='X' && g[1][1]=='X' && g[2][0]=='X';
    
    DEBUG2(tx,tz);
    if(tz > 1 || tx > 1){
        nope();
        return 0;
    }
    if(tx == 1){
        if(xcnt -zcnt == 1)
             cout << "X won." << endl;
        else{
            nope();
        }
        return 0;
    }
    if(tz == 1){
        if(zcnt -xcnt == 0)
             cout << "O won." << endl;
        else{
            nope();
        }
        return 0;
    }
    if(dcnt == 0){
        cout << "It's a draw." << endl;return 0;
    }
    if(xcnt == zcnt){
        cout << "X's turn." << endl;return 0;
    }
    else{
        cout << "O's turn." << endl;return 0;
    }
}