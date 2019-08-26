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

struct node{
    int val;
    node* left;
    node* right;
    node(int val): val(val),left(NULL),right(NULL) {};
};

void inorder(node* root){
    if(root == NULL) return ;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}
void preorder(node* root){
    if(root == NULL) return ;
    cout << root->val << " ";
    inorder(root->left);
    inorder(root->right);
}
void postorder(node* root){
    if(root == NULL) return ;
    inorder(root->left);
    inorder(root->right);
    cout << root->val << " ";
}
node* make(int s,int e,vector<int> const &preorder,int &pindex,unordered_map<int,int> &m1){
    if(s > e) return NULL;
    node *root = new node(preorder[pindex++]);
    int mid = m1[root->val];
    root->left =make(s,mid-1,preorder,pindex,m1);
    root->right =make(mid+1,e,preorder,pindex,m1);
    return root;
}
    
int main(){
    int n;
    cin >> n;
    vector<int> preorderseq(n),inorderseq(n);
    for(int i=0;i<n;i++) cin >> preorderseq[i];
    for(int i=0;i<n;i++) cin >> inorderseq[i];
    
    unordered_map<int,int> m1;
    for(int i=0;i<n;i++){
        m1[inorderseq[i]] = i;
    }
    int pindex = 0;
    node* root = make(0,n-1,preorderseq,pindex,m1);
    inorder(root);
    cout << endl;
    postorder(root);

}