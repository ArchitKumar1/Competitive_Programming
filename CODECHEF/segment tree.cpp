#include<bits/stdc++.h>
using namespace std;

const int N = 100 ;
int n;
int t[2*N] = {0};
int h = sizeof(int) * 8 - __builtin_clz(n);
int d[N];
void build(){
	for(int i=n-1;i>=0;i--){
		t[i] = t[i*2] + t[i*2 +1];
	}
}
void modify(int p,int value){
	for (t[p += n] = value; p > 1; p >>= 1)
		t[p>>1] = t[p] + t[p^1];
}
void calc(int p, int k) {
  if (d[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
  else t[p] = d[p] * k;
}

void apply(int p, int value, int k) {
  t[p] = value * k;
  if (p < n) d[p] = value;
}

void push(int l, int r) {
  int s = h, k = 1 << (h-1);
  for (l += n, r += n-1; s > 0; --s, k >>= 1)
    for (int i = l >> s; i <= r >> s; ++i) if (d[i] != 0) {
      apply(i<<1, d[i], k);
      apply(i<<1|1, d[i], k);
      d[i] = 0;
    }
}
int query(int l, int r) {
  push(l, l + 1);
  push(r - 1, r);
  int res = 0;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
    if (l&1) res += t[l++];
    if (r&1) res += t[--r];
  }
  return res;
}
void modify(int l, int r, int value) {
  if (value == 0) return;
  push(l, l + 1);
  push(r - 1, r);
  bool cl = false, cr = false;
  int k = 1;
  for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(l - 1, k);
    if (cr) calc(r, k);
    if (l&1) apply(l++, value, k), cl = true;
    if (r&1) apply(--r, value, k), cr = true;
  }
  for (--l; r > 0; l >>= 1, r >>= 1, k <<= 1) {
    if (cl) calc(l, k);
    if (cr && (!cl || l != r)) calc(r, k);
  }
}

int main()

{
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
#endif

	cin >> n;
	for(int i=0;i<n;i++)
		cin >> t[i+n];

	build();

	for (int i = 1; i < 2*n; ++i)
		cout<<t[i]<<" ";
	cout << endl;

	modify(2,5,10);
	for (int i = 1; i < 2*n; ++i)
		cout<<t[i]<<" ";
	cout << endl;

#ifndef ONLINE_JUDGE
	cout << endl << endl <<endl <<endl;
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}
