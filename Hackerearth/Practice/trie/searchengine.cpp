#include<bits/stdc++.h>
using namespace std;


struct trie{
    map<char, trie *> children;
    bool end = 0;
    int cnt = 0;
};

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
int searchp(trie *root,string x){
    for (int i = 0; i < x.size();i++){
        char c = x[i];
        if(root->children[c]) root = root->children[c];
        else return 0;
        if(i == x.size() - 1) return root->cnt;
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
    int n, q;
    cin >> n >> q;
    while(n--){
        string x;
        cin >> x;
        insertw(root, x);
    }
    while(q--){
        string x;
        cin >> x;
        cout << searchp(root, x) << endl;
    }
    return 0;
}
    