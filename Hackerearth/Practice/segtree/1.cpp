#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;

const int N = 123456;
int tree[4*N];

void build(int *tree,int *a,int index,int s,int e){
    if(s>e) return;
    if(s == e){
        tree[index] = a[s];
        return;
    }
    int mid = (s + e) / 2;
    build(tree, a, 2 * index, s, mid);
    build(tree, a, 2 * index + 1, mid + 1, e);
    int left = tree[2 * index];
    int right = tree[2 * index + 1];
    tree[index] = min(left, right);
}

int query(int *tree,int index,int s,int e,int qs,int qe){
    if(qs>e || qe < s){
        return 1000000;
    }
    if(s>=qs && e<= qe){
        return tree[index];
    }
    int mid = (s + e) / 2;
    int left = query(tree, 2*index, s, mid, qs, qe);
    int right = query(tree, 2 * index + 1, mid + 1, e, qs, qe);
    return min(left, right);
}

void update(int *tree,int index,int s,int e ,int i,int value){
    //No overlap
    if(i<s || i>e){ 
        return;
    }
    //Reached leaf
    if(s==e){
        tree[index] = value;
        return;
    }
    //Lying in range
    int mid = (s + e) / 2;
    update(tree, 2 * index, s, mid, i, value);
    update(tree, 2 * index + 1, mid + 1, e, i, value);
    tree[index] = min(tree[2 * index], tree[2 * index + 1]);
}
int main(){
    fastio    
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int n,q;
    cin >> n >> q;
    int a[n];

    for (int i = 1; i <= n;i++){
        cin >> a[i];
    }
    int index = 1;
    int s = 1;
    int e = n ;

    build(tree, a, index, s, e);

    for (int i = 0; i < 2 * n;i++){
        cout << tree[i] << " ";
    }
#ifndef ONLINE_JUDGE
		cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}