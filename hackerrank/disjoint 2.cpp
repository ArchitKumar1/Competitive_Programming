#include<bits/stdc++.h>
using namespace std;
const int N = 1234566;
vector<int> parent;
vector<int> size;
vector<int> total;
void make_set(int v){
    parent[v] = v;
    size[v] = 1;
}

int find_set(int v){
    if(  v== parent[v])
        return v;
    return parent[v] = find_set(parent[v]);
}

void union_sets(int a, int b) {
    a = find_set(a);
    b = find_set(b);
    if (a != b) {
        if (size[a] < size[b])
            swap(a, b);
        parent[b] = a;
        total[a] = size[a] + size[b];
        total[b] = size[a] + size[b];
        size[a] += size[b];
        
    }
}

void solve(){
    int n;
    cin >> n;
    parent.resize(2*n);
    size.resize(2*n);
    total.resize(2*n);
    for(int i=0;i<2*n;i++){
       make_set(i);
    }
    for(int i=0;i<n;i++){
        int x,y;
        cin >> x >> y;
        union_sets(--y,--x);
    }
    int mi = 2*n + 10;
    int ma = 0;
    for(int i=0;i<2*n;i++){
        if(total[i] == 0) continue;
        mi = min(mi,size[find_set(i)]);
        ma = max(ma,size[find_set(i)]);
    }
    cout << mi << " " << ma << endl;


}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    solve();
    return 0;
}
    