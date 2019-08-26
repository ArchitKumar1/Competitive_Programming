#include<bits/stdc++.h>
using namespace std;
const int N = 123456;

int par[N],size[N];
map<int, int> m1;

void make(int i){
    par[i] = i;
    size[i] = 1;
}
int find(int v){
    if(v == par[v])
        return v;
    return par[v] = find(par[v]);
}
void merge(int a,int b){
    a = find(a);
    b = find(b);
    if(a!=b){

        if(size[a] < size[b])
            swap(a, b);
        par[b] = a;
        size[a] += size[b];
        
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n,p;
    cin >> n >> p;

    for (int i = 0;i<n;i++){
        make(i);
    }
    for (int i = 0;i<p;i++){
        int x,y;
        cin >> x >> y;
        merge(x, y);
    }
    for (int i = 0; i < n;i++){
        int p = par[i];
        if(!m1[p]){
            m1[p] = 1;
        }
    }

    vector<int> nums;
    for(auto it : m1){
        int a = it.first;
        nums.push_back(size[it.first]);
    }
    long long int total = 0LL;
    long long int sum= 0LL;
    for(auto x : nums){
        total += (long long int)sum * x;
        sum += x;
    }
    cout << total << endl;
    return 0;
}