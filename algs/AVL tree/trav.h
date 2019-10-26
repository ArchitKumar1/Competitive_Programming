struct node{
    node(int val) : data(val),left(NULL),right(NULL){};
    int data;
    node* left;
    node* right;
    int hieght;
};
using namespace std;
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

