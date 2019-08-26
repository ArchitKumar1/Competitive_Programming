#include<bits/stdc++.h>
using namespace std;

const int N = 2345678;

int a[N];
int tree[4 * N];

void build(int s, int e,int index){
    if(s == e){
        tree[index] = a[s];
        return;
    }
    int mid = (s + e) / 2;
    build(s, mid , 2 * index);
    build(mid + 1, e, 2 * index+1);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}
int query(int s,int e,int qs,int qe,int index){
    if(qs>e || qe < s){
        return 0;
    }
    if(s>=qs && e<= qe){
        return tree[index];
    }
    int mid = (s + e) / 2;
    return query(s, mid, qs, qe, 2 * index) + query(mid+1,e,qs,qe,2*index+1);
}
void update(int s,int e,int val,int i,int index){
    if(i<s || i>e){
        return;
    }
    if(s == e){
        tree[index] = val;
        return;
    }
    int mid = (s + e) / 2;
    update(s, mid, val,i, 2 * index );
    update(mid + 1, e, val,i, 2 * index + 1);
    tree[index] = tree[2 * index] + tree[2 * index + 1];
}

int main() {
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
    int s = 0;
    int e = n - 1;
    int index = 1;
    build(s, e, index);

    
    for (int i = 0; i < q;i++){
        int x, y;
        cin >> x >> y;
        if(x == 1){

        }
    }

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}