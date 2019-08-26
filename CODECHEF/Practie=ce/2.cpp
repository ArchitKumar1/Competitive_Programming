#include<bits/stdc++.h>
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;



struct node{
    int x;
    node *left;
    node *right;
    node(int a){
        x = a;
        left = NULL;
        right = NULL;
    }
};

node* addnode(node* root,int val){
    if(!root) return new node(val);
    if(val < root->x) root->left = addnode(root->left, val);
    else root ->right = addnode(root->right, val);   
    return root;
}

void find(node* root,int val){
    if(!root) return;
    if(!root->x  == val){
        cout << "found";
        return;
    }
    else if(root->x > val) find(root->left,val);
    else find(root->right, val);
    
}

void dfs(node* root){
    if(!root) return; 
    dfs(root->left);
    cout << root->x << " ";
    dfs(root->right);
    
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    node *root = NULL;
    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        root = addnode(root, x);
    }
    dfs(root);
    find(root, 4);
#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}