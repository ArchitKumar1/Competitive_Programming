#include<bits/stdc++.h>
using namespace std;
struct Point
{
    double x;
    double y;
    Point operator+(const Point& p1) {return {x+p1.x,y+p1.y};}
    Point operator-(const Point& p1) {return {x-p1.x,y-p1.y};}
    Point operator*(const Point& p1) {return {x*p1.x,y*p1.y};}
};

int main()
{

    int n,m;
    cin >> n >> m;
    vector<vector<pair<int,int> > >p1(n);

    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            int x,y;
            cin >> x >> y;
            p1[0].push_back(make_pair(x,y));
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0 ; j < m ; j++){
            cout<<p1[i][j].first<<" "<<p1[i][j].second<<endl;
        }
    }
    return 0;
}
