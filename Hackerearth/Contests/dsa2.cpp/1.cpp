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
 
const int mod = pow(10,9) +9;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;
 
 
/////////////////////////////
 
 
struct node{
    node* child[26];
    int cnt = 0;
    int end = 0;
    set<int>  all;
};


void insert(string s,node* root,int pos){
    for(int i=0;i<s.length();i++){
        char c = s[i];
        if(root->child[c-'a']){
            root= root->child[c-'a'];
            root->end +=1;
            root->all.insert(pos);
            //sort(ALL(root->all));
        }else{
            root->child[c -'a'] = new node();
            root = root->child[c-'a'];
        }
    }
    
    root->end +=1;
}

int calc(string prefix,node* root,int l,int r){
    for(int i=0;i<prefix.length();i++){
        char c = prefix[i];
        if(root->child[c-'a'] == NULL){
            return 0;
        }else{
            root = root->child[c-'a'];
        }
    }
    // int y = 1;
    // int x = 1;
    auto x = lower_bound(root->all.begin(),root->all.end(),l);
    auto y = lower_bound(root->all.begin(),root->all.end(),r);
    return 1-2;
}

int find(string prefix,node* root){
    for(int i=0;i<prefix.length();i++){
        char c = prefix[i];
        if(root->child[c-'a'] == NULL){
            return 0;
        }else{
            root = root->child[c-'a'];
        }
    }
    return 1;
}
int main(){
 
FASTIO    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif      
    
    string s;
    cin >> s;
    vector<string> alls;
    alls.PB(s);
    node* root = new node();
    insert(s,root,0);

    int q;
    cin >> q;
    int total = 0;
    while(q--){
        int x;
        cin >> x;
        if(x == 1){
            int p,n;
            char c;
            cin >> p >> n >> c;
            n--;
            string temp = alls[n].substr(0,p-1) + c;
            alls.PB(temp);
            ++total;
            insert(temp,root,total);
        }else  if(x == 2){
            int p,n;
            cin >> p >> n;
            n--;
            string temp = alls[n].substr(0,p);
            alls.PB(temp);
            ++total;
            insert(temp,root,total);
        }else{
            int l,r;
            string temp;
            cin >> l >> r >> temp;
            int ans = calc(temp,root,l,r);
            if(ans >= 1){
                cout << "yes";
            }else{
                cout << "no";
            }
            cout << endl;
        }
    }
    
    
    return 0;
}