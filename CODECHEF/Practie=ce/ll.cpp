#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);
ll mod =1e+9 +7;
typedef pair<int,int> Pair;
typedef vector<int,int> vdi;
typedef vector<int> vi;
vector<Pair> v1;

struct node{
	int data;
	struct node* next;
};

struct node *nnode(int n){
	struct node* Node=new struct node();
	Node->data=n;
	return Node;
};
int main()
{

	int n;
	cin>>n;
	int x;
	struct node *head;
	struct node *llt,*y;


	head=llt;
	while(head!=NULL){
		cout<<head->data<<endl;
		head=head->next;
	}





	//cerr << "time = " << clock() << " ms" << '\n';
	return 0;
}
