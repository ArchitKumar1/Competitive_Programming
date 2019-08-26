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

/////////////////////////////

struct trie{
    map<char, trie *> children;
    int pre = 0;
    int end = 0;

};

void addw(string s,trie* root){
    for (int i = 0;i<s.length();i++){
        char c = s[i];
        if(root->children[c]  == NULL){
            trie *nn = new trie();
            root->children[c] = nn;
            root = nn;
        }else root = root->children[c];
        root->pre+= 1;
    }
    root->end += 1;
}
bool findw(string s,trie* root){
    for (int i = 0; i < s.length();i++){
        char c = s[i];
        if(root->children[c] == NULL) return 0;
        else root = root->children[c];     
    }
    if(root ->end == 1) return 1;
    else return 0;
}


string lcp(trie * root,int x){
    queue<pair<string,trie *>> qq;
    qq.push({"",root});
    vector<string> fans;
    while(!qq.empty()){
        pair<string, trie *> temp = qq.front();
        trie *root = temp.second;
        string strval = temp.first;
        qq.pop();
        if(root->pre == x ){
            fans.PB(strval);
        }
        for(auto c : root->children){
            qq.push({ strval + c.first,c.second});
        }
    }
    return *fans.rbegin();
}

int findprefix(trie * root,string s){
    for (int i = 0; i < s.length();i++){
        char c = s[i];
        if(root-> children[c]){
            root = root->children[c];
        }else{
            return 0;
        }
    }
    return root->pre;
}
int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int q;
    cin >> q;
    trie *root = new trie();
    for (int i = 0; i < n;i++){
        string s;
        cin >> s;
        addw(s, root);
    }
    for (int i = 0; i < q;i++){
        string s;
        cin >> s;
        cout << findprefix(root, s) << endl;
    }
}