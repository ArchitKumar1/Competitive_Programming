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
 
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
#define REP(i,a,b) for(int i = a;i<=b;i++)

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

const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;


/////////////////////////////

struct node{
    char c;
    node *left;
    node *right;
    node(char c): c(c),left(NULL),right(NULL){};
};


void inorder(node* root){
    if(root == NULL) return;
    inorder(root->left);
    cout << root->c << " ";
    inorder(root->right);
}
bool op(char c){
    return (c == '+' || c == '*' || c == '/' || c == '-');
}
int solve(int a,int b,char o){
    if(o == '*') return a*b;
    if(o == '/') return a/b;
    if(o == '+') return a+b;
    if(o == '-') return a-b;
}
int infix_solver(string s){
    int l = s.length();
    stack<int> all;

    for(char c : s){
        if(!op(c)){
            all.push(c-'0');
        }else{
            int x = all.top();all.pop();
            int y = all.top();all.pop();
           // trace(x,y,c,x-'0',y-'0');
            all.push(solve(x,y,c));
        }
    }
    cout << all.top() << endl;
}

node* tree_from_infix(string s){
    stack<node*> st;

    for(char c: s){
        if(!op(c)){
            st.push(new node(c));
        }else{
            node* x= st.top();st.pop();
            node* y = st.top();st.pop();
            node* t = new node(c);
            t->left =x ;
            t->right = y;
            st.push(t);
        }
    }
    return st.top();
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
   
    
        
    string s;
    cin >> s;

    node* root = tree_from_infix(s);
    inorder(root);
    return 0;
}




