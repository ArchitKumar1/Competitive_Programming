#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;
typedef vector<int,int>  vdi;
typedef vector<int> vi;
vector<Pair> v1;


struct node{
	int data;
	struct node *left;
	struct node *right;

};

struct node *newNode(int val){
	struct node* n=new node();
	n->data=val;
	n->left=NULL;
	n->right=NULL;
	return n;
};

int sum(struct node* root){
	if(root==NULL)
		return 0;
	else
		return (root->data+sum(root->right)+sum(root->left));
}

bool isleaf(struct node* root){
	if(root->right==NULL && root->left==NULL)
		return 1;
	else
		return 0;
}
void sumofparent(struct node *root,int &sum,int x){
	if(root==NULL)
		return;
	if(root->right)
		sum+=root->right->data;
	sumofparent(root->left,sum,x);
	sumofparent(root->right,sum,x);
}

void sumofleaves(struct node *root,int &sum){
	if(isleaf(root)){
		sum+=root->data;
		return;
	}
	if(root->right)	sumofleaves(root->right,sum);
	if(root->left) sumofleaves(root->left,sum);
}
int main()
{
	struct node *root = newNode(1);
    root->left = newNode(2);
    root->left->left = newNode(4);
    root->left->right = newNode(5);
    root->left->left->right = newNode(2);
    root->right = newNode(3);
    root->right->right = newNode(8);
    root->right->right->left = newNode(6);
    root->right->right->right = newNode(7);

	int sum=0;
	sumofleaves(root,sum);
	cout<<sum<<endl;
	return 0;

}
