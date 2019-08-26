#include <iostream>
using namespace std;
#define forn(i,n) for(int i=0;i<n;i++)

struct node {
    node(int data) : data(data) ,left(NULL),right(NULL){};
    int data;node* left;node* right;
};

void dfs(node* root){
    if(!root) return;
    cout << root->data <<  " ";
    dfs(root->left) ,dfs(root->right);
}
node* add(node* root,int data){
    if(!root) return new node(data);
    if(data >= root->data) 
        root->right = add(root->right,data);
    else 
        root->left = add(root->left,data);
    return root;
}
int main()
{
    int n;cin >> n;int a[n];
    forn(i,n) cin >> a[i];
    node * r = new node(a[0]);
    forn(i,n-1)
        add(r,a[i+1]);
    dfs(r);
    return 0;
}