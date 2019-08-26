#include<bits/stdc++.h>
#define ll long long
#define TC int t;cin>>t;while(t--)
using namespace std;

struct point {
	double x,y;

	point operator+ (struct point &p){
		return {x + p.x , y + p.y};
	}

	point operator- (struct point &p){
		return {x - p.x , y - p.y};
	}

	double operator/ (struct point &p){
		return {(x - p.x) / (y - p.y)};
	}

	point operator* (struct point &p){
		return {x * p.x , y * p.y};
	}
};

const int n = 1000;
struct point P[n];


int main(){

	int n;
	cin >> n;

	for (int i = 0; i < n; i++){
		cin >> P[i].x >> P[i].y;
	}
	cout << endl;


//	for (int i = 0; i < n-1; i++){
//		point a = P[i] + P[i+1];
//		cout<< a.x <<" "<< a.y << endl;
//	}
//	cout << endl;
//	for (int i = 0; i < n-1; i++){
//		point a = P[i] * P[i+1];
//		cout<< a.x <<" "<< a.y << endl;
//	}
//	cout << endl;
//	for (int i = 0; i < n-1; i++){
//		double x =  P[i] / P[i+1];
//		cout << x << endl;
//	}
//	cout << endl;
//	for (int i = 0; i < n-1; i++){
//		point a = P[i] - P[i+1];
//		cout<< a.x <<" "<< a.y << endl;
//	}
//	cout << endl;
	return 0;
}
