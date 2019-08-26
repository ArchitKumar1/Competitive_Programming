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

const int mod = pow(10,9)+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

struct node{
    int val;
    node *left,*right;
    node(int d) : val(d) , left(NULL),right(NULL) {};
};
map<int,string> m1;
map<string,int> m2;
void insert(node* root,int theone,int val,char dir,string s){
    if(root == NULL) return ;
    if(root->val == theone){
        if(dir == 'L'){
            root->left = new node(val);
            m1[val] = s+'L';
            m2[s+'L'] = val;
        }else{
            root->right = new node(val);
            m1[val] = s+'R';
            m2[s+'R'] = val;
        }
        return;
    }
    insert(root->left,theone,val,dir,s + 'L');
    insert(root->right,theone,val,dir,s+'R');

}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    int q;
    cin >> q;

    node* root = new node(1);
    for(int i=0;i<n-1;i++){
        int p,c;
        char dir;
        cin >> p >> c >> dir;
        insert(root,p,c,dir,"");
    }
    while(q--){
        int x;
        cin >> x;
        string temp = m1[x];
       // DEBUG1(temp);
        for(char &c : temp){
            if(c == 'L'){
                c = 'R';
            }else{
                c = 'L';
            }
        }
    //DEBUG1(temp);
        if(x == 1){
            cout << "1"<< endl;
        }
        else{
            if(m2[temp]){
            cout << m2[temp];
            }else{
                cout << "-1";
            }
            cout << endl;
        }
        
    }
    // for(auto x : m1){
    //     cout << x.F << " " << x.S << endl;
    // }
    // for(auto x : m2){
    //     cout << x.F << " " << x.S << endl;
    // }
}