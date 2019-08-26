#include<bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define mset(a, val) memset(a, val, sizeof(a));
#define TC int t; cin >> t; while(t--)
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<pi> vpi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<vl> vvl;


const int maxn = 100000;



struct Point {
  double x, y;
  Point() : x(0), y(0) {}
  Point(const double& x, const double& y) : x(x), y(y) {}
  void swap(Point& other) {
	  using std::swap;
	  swap(x, other.x);
	  swap(y, other.y);
  }
   Point operator = (const Point& other) {
    	return{other.x,other.y};}
   Point operator + (const Point& other) {
    	return{x + other.x, y + other.y};}
   Point operator - (const Point& other) {
    	return{x - other.x, y - other.y};}
   Point operator * (const double& factor) {
    	return{x * factor, y * factor};}
   Point operator / (const double& factor) {
    	return{x/ factor, y / factor};}
	
};
istream& operator >> (istream& is,Point& point){
		return is >> point.x >> point.y;
	}
ostream& operator << (ostream& os,Point& point){
	return os << point.x << " " << point.y;
}


int main(){
#ifndef ONLINE_JUDGE 
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Point x,y;
	cin >> x;
	y = x / 3 * 4;
	cout << y << endl;
#ifndef ONLINE_JUDGE
	cerr<< "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
	return 0;
}