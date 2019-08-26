#include<bits/stdc++.h>
using namespace std;

vector<int> v(400001);
vector<bool> laxy(400001);

void upd(int id,int l,int r,int x){
	lazy[id] = lazy[id]^x;
	if(x) v[id] = r-l-v[id];
}
void shift(int id,int l,int r){
	int mid = (l+r)/2;
	upd(id*2,l,mid,lazy[id]);
	upd(id*2+1,l,mid,lazy[id]);
	lazy[id] = 0;
}

int update(int x,int y,int val,int id,int l,int r){
	if(x >=r || l>=y) return ;
	if(x <= l && r <= y){
		upd(id,l,r,val);
		return;
	}
	shift(id,l,r);
	int mid = (l+r)/2;
	update(x,y,val,id*2,l,mid);
	update(x,y,val,id*2+1,mid,r);
	v[id] = v[id*2] + v[id*2 + 1];
}

int sum(int x,int y,int id,int l,int r){
	if(x >=r || l >= y) return 0;
	if(x <= l && r <= y) return v[id];
	shift(id,l,r);
	int mid = (l+r) >> 1;
	return sum(x,y,id*2,l,mid) + sum(x,y,id*2 +1,mid,r);
}

}
