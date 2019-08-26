#include<bits/stdc++.h>
#define mset(a,v) memset(a,v,sizeof(a));
#define TC int t;cin >> t;while(t--)
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

const int N = 210000;

vector<int> e[N];

int colw[N];
int colb[N];
int va[N];
int vb[N];

void dfs1(int s){
    colb[s] = 1;
    va[s] = 1;
    for(auto c : e[s]){
        if(colb[c] == 0 && !va[c]){
            dfs1(c);
        }
    }
}

void dfs2(int s){
    colw[s] = 0;
    vb[s] = 1;
    for(auto c : e[s]){
        if(colw[c] == 1 && !vb[c]){
            dfs2(c);
        }
    }
}
int main()
{
    //fastio
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    int n;
    cin >> n;
    for (int i = 0; i < n;i++){
        int x;
        cin >> x;
        colw[i] = colb[i] = x;
    }
    for (int i = 0; i < n - 1;i++){
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    int a=0 , b = 0;
    for (int i = 0; i < n;i++){
        if(colb[i] == 0){
            dfs1(i);
            a++;
        }
    }
    for (int i = 0; i < n;i++){
        if(colw[i] == 1){
            dfs2(i);
            b++;
        }
    }

    cerr << a << " " << b <<  " " << endl;
    cout << min(a, b) << endl;
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif

	return 0;

}
