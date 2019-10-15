#include<bits/stdc++.h>
using namespace std;
#define ll long long int


struct point{
    double x = 0.0, y = 0.0;
    point(){
        x = 0.0;
        y = 0.0;
    }
    point(const double a, const double b){
        x = a;
        y = b;
    }
    double operator* ( const point & b){
        return x * b.x + y * b.y;
    }
    double operator% ( const point & b){
        return x * b.y - y * b.x;
    }
    point operator+(const point & b){
        return {x + b.x, y + b.y};
    }
    point operator-(const point & b){
        return {x - b.x, y - b.y};
    }
};
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n;i++){
        a[i] = i + 1;
    }
    for
    return 0;
}