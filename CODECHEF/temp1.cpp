#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);cout.tie(0);

typedef pair<int,int> Pair;
typedef vector<int,int>  vdi;
typedef vector<int> vi;
vector<Pair> vpi;

template<typename T> T uax(T a,T b){ if(a>=b) return a; else return b;}
template<typename T> T uix(T a,T b){ if(a<=b) return a; else return b;}

namespace MATH{
	template<typename T>
	bool isprime(T x){
		for(T i=2;i*i<=x;i++)
			if(x%i==0)
				return 0;
		return 1;
	}
	template<typename T>
	T gcd(T a,T b){
		if(a == 0) return b;
		if(b == 0) return a;
		if(a == b) return a;
		if(a > b) return gcd(a-b,b);
		return gcd(a,b-a);
	}
	template<typename T>
	T lcm(T a,T b){
		return ((a*b)/gcd(a,b));
	}
	template<typename T>
	T pow(T a, T b, T m) {
		a %= m;
		T res = 1;
		while (b > 0) {
			if (b & 1)
				res = res * a % m;
			a = a * a % m;
			b >>= 1;
		}
		return res;
	}
	template<typename T>
	T fact(T a){
		T val = 1;
		for(T i = 1; i <= a;i++){
			val=val*i;
		}
		return val;
	}
	template <typename T>
	void sieve(vector<T> &primes, T n){
		for(T i=2;i<n;i++){
			if(primes[i]==0){
				if(!MATH::isprime(i)){
					for(T j=i;j<=n;j=j+i)
						primes[j]=1;
				}
			}
		}
	}
	namespace FIBBONACI{
		template<typename T>
		void multiply(T F[2][2], T M[2][2]);
		template<typename T>
		void power(T F[2][2], T n);
		template<typename T>
		void power(T F[2][2], T n)
		{
		  if( n == 0 || n == 1)
			  return;
		  T M[2][2] = {{1,1},{1,0}};

		  power(F, n/2);
		  multiply(F, F);

		  if (n%2 != 0)
			 multiply(F, M);
		}
		template<typename T>
		void multiply( T F[2][2], T M[2][2])
		{
		  T x =  F[0][0]*M[0][0] + F[0][1]*M[1][0];
		  T y =  F[0][0]*M[0][1] + F[0][1]*M[1][1];
		  T z =  F[1][0]*M[0][0] + F[1][1]*M[1][0];
		  T w =  F[1][0]*M[0][1] + F[1][1]*M[1][1];

		  F[0][0] = x;
		  F[0][1] = y;
		  F[1][0] = z;
		  F[1][1] = w;
		}
		template<typename T>
		T fib(T n)
		{
		  T F[2][2] = {{1,1},{1,0}};
		  if (n == 0)
			return 0;
		  power(F, n-1);
		  return F[0][0];
		}
	}

}
namespace SEARCH{

	template<typename T>
	T binarysearch(T arr[], T l, T r, T x)
	{
		if (r >= l) {
			int mid = (l + r)/ 2;
			if (arr[mid] == x)
				return mid;
			if (arr[mid] > x)
				return binarysearch(arr, l, mid - 1, x);
			return binarysearch(arr, mid + 1, r, x);
		}
		return -1;
	}
}
namespace BT{
	struct node {
		int data;
		struct node *right;
		struct node *left;
	};
	struct node *newnode(int x){
		struct node *n = new node();
		n->data=x;
		n->right=NULL;
		n->left-NULL;
		return n;
	}
	void calcsum(struct node *root, int &sum){
		sum+=root->data;
		if(root->left) calcsum(root->left,sum);
		if(root->right) calcsum(root->right,sum);

	}
	void calclsum(struct node *root, int &sum){
		if(root->left)
			sum+=root->left->data;
		if(root->right) calclsum(root->right,sum);
		if(root->left) calclsum(root->left,sum);
	}
	void calcrsum(struct node *root, int &sum){
		if(root->right)
			sum+=root->right->data;
		if(root->left) calcrsum(root->left,sum);
		if(root->right) calcrsum(root->right,sum);
	}
	void calcleafsum(struct node *root,int &sum){
		if(root->right==NULL && root->left==NULL)
			sum+=root->data;
		if(root->left) calcleafsum(root->left,sum);
		if(root->right) calcleafsum(root->right,sum);
	}
	void calcleaflsum(struct node *root, int &sum){
		if( root->left && root->left->right==NULL && root->left->left==NULL)
			sum+=root->left->data;
		if(root->left) calcleaflsum(root->left,sum);
		if(root->right) calcleaflsum(root->right,sum);
	}
	void calcleafrsum(struct node *root, int &sum){
		if( root->right && root->right->right==NULL && root->right->left==NULL)
			sum+=root->right->data;
		if(root->left) calcleafrsum(root->left,sum);
		if(root->right) calcleafrsum(root->right,sum);
	}
}

int main()
{
	int n;
	cin >> n;
	vi v1;
	for(int i = 0; i < n; i++) v1.push_back(1);
	for(int i = 0; i < n; i++) cout<<v1[i]<<" ";
	return 0;

}
