#include<bits/stdc++.h>
using namespace std;

struct node{ 
    int data;
    node* left;
    node* right;
    node(int val) : data(val), left(NULL), right(NULL){};
};

void inorder(node* root){
    if(root == NULL){ return;}
    inorder(root->left);
    cout << root->data << endl;
    inorder(root->right);
}

int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    
    
    return 0;
}