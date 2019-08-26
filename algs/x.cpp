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

const int N = 5* 1e5 + 100;
int tree[4*N];
int a[N];
void build(int *a,int index,int s,int e){
    if(s == e){
        tree[index] = a[s];
        return ;
    }
    int mid = (s + e) / 2;
    build(a, 2 * index, s, mid);
    build(a, 2 * index + 1, mid + 1, e);
    int left = tree[2 * index];
    int right = tree[2 * index + 1];
    //Modifications
    tree[index] = min(left , right);
}

int query(int index,int s,int e,int qs,int qe){
    if(qs>e || qe < s){
        return 100000;
    }
    if(s>=qs && e<= qe){
        return tree[index];
    }
    int mid = (s + e) / 2;
    int left = query( 2*index, s, mid, qs, qe);
    int right = query( 2 * index + 1, mid + 1, e, qs, qe);
    //Modifications
    return min(left , right);
}

void update(int index,int s,int e ,int i,int value){
    if(i<s || i>e)
        return;
    if(s==e){
        tree[index] = value;
        return;
    }
    int mid = (s + e) / 2;
    update( 2 * index, s, mid, i, value);
    update( 2 * index + 1, mid + 1, e, i, value);
    //MODIFICATIONS
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}
int main(){
    fastio    
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    int q;
    cin >> q;

    for (int i = 0; i < n;i++){
        cin >> a[i];
    }
    int index = 1;
    int s = 0;
    int e = n -1;

    build(a, index, s, e);

    
    while(q--){
        int l, r;
        cin >> l >> r;
        cout << query(index, s, e, l, r) << endl;
    }
    

#ifndef ONLINE_JUDGE
		cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}