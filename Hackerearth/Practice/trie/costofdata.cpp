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

const int mod = 10*9+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

const int N = 123456;
const int c_max = 26;


struct trie{
    trie *child[c_max];
    int pre = 0;
    bool end = 0;
};


void insert(trie* root,string s){
    for(char c : s){
        if(!root->child[c - 'a']){
            root->child[c - 'a'] = new trie();
        }
        root = root->child[c - 'a'];     
        root->pre+=1;
    }
    root->end = 1;
} 
bool find(trie *root,string s){
    for(char  c : s){
        if(!root->child[c - 'a']) return 0;
        else root = root->child[c - 'a'];  
    }
    return root->end;
}

int dfs(trie* root){
    int chil = 0;
    int temp = 0;
    for(int i=0;i<c_max;i++){
        if(root->child[i]){
            chil += dfs(root->child[i]);
        }
    }
    return 1 + chil;
}

        
int prefind(trie* root,string s){
    for(char c: s){
        root = root->child[c- 'a'];
    }
    return root->pre;
}
        
int main(){
    trie *root = new trie();
    int n;
    cin >> n;
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        insert(root,s);
    }
    
    
    cout << dfs(root);
    
    
}
    