#pragma GCC optimize ("O3")
#pragma comment(linker, "/stack:200000000")

#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
const double eps = 1e-9;
struct pt{
    double x, y;
    pt(double a, double b){
        x = a;
        y = b;
    }
    pt(){x = 0.0, y = 0.0;}
    pt operator+ (const pt& t){
        return {x + t.x, y + t.y};
    }
    pt operator- (const pt& t){
        return {x - t.x, y - t.y};
    }
    pt operator* (const pt& t){
        return {x * t.x, y * t.y};
    }
    pt operator/ (const pt& t){
        return {x / t.x, y / t.y};
    }
    pt operator* (const double& t){
        return {x * t ,y*t};
    }
    pt operator/ (const double& t){
        return {x / t ,y/t};
    }
};
pt operator*(double a,pt b){
    return b * a;
}
struct line{
    double a, b, c;  
};
double dot(pt a,pt b){
    return a.x * b.x + a.y * b.y;
}
double mag(pt a){
    return sqrt(dot(a, a));
}
double cross(pt a,pt b){
    return a.x * b.y - a.y * b.x;
}
pt intersect(pt a,pt b,pt c,pt d){
    return a + cross(c - a, d) / cross(b, d) * b;
}
void solve(){

    pt p[4];
    for (int i = 0; i < 4;i++){
        cin >> p[i].x >> p[i].y;
    }
    pt ans = intersect(p[0], p[1], p[2], p[3]);
    cout << ans.x << " " << ans.y << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    solve();return 0;
}