#include<bits/stdc++.h>
using namespace std;


struct trie{
    map<char, trie *> children;
    bool end = 0;
    int cnt = 0;
};
map<string,int> m1;
vector<string> fans;
void explore(trie* root,string x){
    list<pair<trie*,string>> ss;
    pair<trie *, string> temp = {root, x};
    ss.push_back(temp);
    while(!ss.empty()){
        pair<trie *, string> temp = ss.front();
        ss.pop_front();
        trie* r  = temp.first;
        string s = temp.second;
        if(r->end == 1)
            cout << s << endl;
        for(auto it : r->children){
            ss.push_back({it.second, s + it.first});
        }
    }
}
void insertw(trie *root,string x){
    for(int i=0;i<x.size();i++){
        char c = x[i];
        if(root->children[c] == 0){
            trie *nn = new trie();
            root->children[c] = nn;
            root = nn;
        }else root = root->children[c];
        root->cnt += 1;
        if(i == x.size() - 1) root->end = 1;
    }
}
bool searchw(trie *root,string x){
    for (int i = 0; i < x.size();i++){
        char c = x[i];
        if(root->children[c]) root = root->children[c];
        else return 0;
        if(i == x.size() - 1 && root->end == 1) return 1;
    }
}
trie* searchq(trie *root,string x){
    for (int i = 0; i < x.size();i++){
        char c = x[i];
        if(root->children[c]) root = root->children[c];
        else return NULL;
        if(i == x.size() - 1 ) return root;
    }
}
void deletew(trie *root,string x){
    for (int i = 0; i < x.size();i++){
        char c = x[i];
        if(root->children[c]) root = root->children[c];
        else return;
        if(i == x.size() - 1) root->end = 0;
    }
}
int main(){
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    trie *root = new trie();
    int n;cin >> n;
    while(n--){
        string x;
        cin >> x;
        transform(x.begin(), x.end(), x.begin(), ::tolower);
        if(m1[x]) continue;
        m1[x] = 1;
        insertw(root, x);
    }
    int q;cin >> q;
    while(q--){
        string x;
        cin >> x;
        trie *ans = searchq(root, x);
        if(ans!=NULL){
            fans.clear();
            explore(ans, x);
            // sort(fans.begin(), fans.end());
            // for(auto c : fans){
            //     cout << c << endl;
            // }
        }else{
            cout << "No suggestions" << endl;
        }
    }
    
    return 0;
}
    