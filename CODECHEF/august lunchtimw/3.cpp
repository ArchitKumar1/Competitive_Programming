#include<bits/stdc++.h>
using namespace std;


void solve(){
    double x1,x2,y1,y2;
    double r1,r2;
    cin >> x1 >> y1 >> r1 >> x2 >> y2 >> r2;
    double dist = 1.0*pow(pow(x1-x2,2) + pow(y1-y2,2),0.5);
    bool ok = 1;
    if(dist > r1 + r2){
        ok = 1;
    }else if(dist <= abs(r1 - r2) && r2 >=r1){
        ok= 0;
    }else{
        ok = 1;
    }
    double total = 2*3.141592653;
    double incre = 1000;
    double base = 0;
    double step =total/incre;
    if(ok == 1){
        cout << "YES" << endl;
        double x,y;
        for(int i=0;i<incre;i++){
            x = x1 + r1*sin(total/2 - step*incre);
            y = y1 + r1*cos(total/2 - step*incre);
            double dist = 1.0*pow(pow(x-x2,2) + pow(y-y2,2),0.5);
            if(dist <= r2){
                continue;
            }
            else{
                cout << x << " " << y << endl;
                break;
            }
        }
    }else{
        cout << "NO" << endl;
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;

}