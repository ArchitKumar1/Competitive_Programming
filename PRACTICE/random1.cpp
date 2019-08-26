#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;
int main() {
    int n,m;
    cin >> n >> m;
    int a[n][m],b[n][m],rank[n][m];
    memset(b,0,sizeof(b));
    memset(rank,0,sizeof(rank));
    vector<pair<int,pair<int,int>>> v1;
    for(int i=0;i<n;i++){
        for(int j= 0;j<m;j++){
            cin >> a[i][j];
            v1.push_back({a[i][j],{i,j}});
        }
    }
    sort(v1.begin(),v1.end());
    map<int,int> m1;
    int xtreme = 0;

    for(auto xx : v1){
        //cout << "XXXXX" << xx.first << endl;
        int val = xx.first;
        int s = xx.second.first;
        int e = xx.second.second;
        if(m1[val] == 0){
            ++xtreme;
            m1[val] = 1;
        }
        list<pair<int,int>> ll;
        ll.push_back({s,e});
        //cout << "S" << s << "E" << e << endl;
        while(!ll.empty()){
            pair<int,int> pp = ll.front();
            ll.pop_front();
            int x = pp.first;
            int y = pp.second;
            //cout << "x" << x << "y" << y << endl;
            if(b[x][y] == 1) continue;
            b[x][y] = 1;
            for(int i = 0;i<n;i++){               
                if(a[i][y] == val){
                    ll.push_back({i,y});
                    rank[i][y] = xtreme;
                }               
            }
            for(int j = 0;j<n;j++){ 
                if(a[x][j] == val){
                    ll.push_back({x,j});
                    rank[x][j] = xtreme;
                }               
            }            
        } 
    }
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout << rank[i][j] << " ";
        }cout << endl;
    }
    return 0;
}
