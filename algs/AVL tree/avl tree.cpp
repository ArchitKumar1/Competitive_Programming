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


/////////////////////////////
struct node{
    node(int val) : data(val),left(NULL),right(NULL){};
    int data;
    node* left;
    node* right;
    int hieght;
};

namespace rotate{
    node* ll(node* root){
        node* newroot = root->left;
        root->left = newroot->right;
        newroot->right = root;
        return newroot;
    }
    node* rr(node* root){
        node* newroot = root->right;
        root->right= newroot->left;
        newroot->left = root;
        return newroot;
    }
}
namespace trav{
    void inorder(node* root){
        if(root == NULL) return ;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
    void post(node* root){
        if(root == NULL) return ;
        post(root->left);
        post(root->right);
        cout << root->data << " ";
    }
    void pre(node* root){
        if(root == NULL) return ;
        cout << root->data << " ";
        pre(root->left);
        pre(root->right);
    }
}
node* add(node* root,int val){
    if(root == NULL) return new node(val);
    if(val >= root->data){
        root->right = add(root->right,val);
    }else{
        root->left = add(root->left,val);
    }
    return root;
}


int main(){
    FASTIO
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    node* root = new node(10);
    int n;
    cin >> n;

    forn(i,n){
        int x;
        cin >> x;
        add(root ,x);
    }
    trav::inorder(root);l();
    trav::pre(root);l();

    root = rotate::ll(root);

    trav::inorder(root);l();
    trav::pre(root);l();
    
}




