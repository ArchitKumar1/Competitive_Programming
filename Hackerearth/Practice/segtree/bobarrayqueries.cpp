#include<bits/stdc++.h>
using namespace std;
      
const int N = 5e6 +100;
int arr[N];
int tree[4 * N];

void build(int s,int e,int index){
    if(s == e){
        tree[index] =  tree[index] = arr[s];
    }
    else{  
        int mid = (s + e) / 2;
        build(s,mid,2*index);
        build(mid+1,e,2*index+1);
        tree[index] = tree[2*index] + tree[2*index+1];
    }
}


void update(int s,int e, int index,int val,int pos){
    if(s > pos || e < pos) return;
    if(s == e){
        arr[pos] = val;
        tree[index] = val;
    }
    else{
        int mid = (s + e) / 2;
        update(s ,mid , 2 *index , val,pos);
        update(mid+1,e, 2* index + 1,val,pos);
        tree[index] = tree[2*index + 1] + tree[2*index];
    }
}

int query(int s,int e,int index, int ss,int ee){
    if(ee < s || ss > e){
        return 0;
    }
    if(ee >= e && ss <= s){
        return tree[index];
    }
    int mid = (s+e)/2;
    int a = query(s,mid,2*index,ss,ee);
    int b = query(mid+1,e,2*index +1,ss,ee);
    return a+b;
}
   
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int s = 0;
    int index = 1;
    int e = n-1;

    int q;
    cin >> q;
    while(q--){
        int a;
        cin >> a;
        if(a == 1){
            int x;
            cin >> x;
            --x;
            update(s, e, index, arr[x] + 1, x);
            
        }
            else if( a == 2){
            int x;
            cin >> x;
            --x;
            update(s, e, index, max(0,arr[x] -1), x);
            
    }else{
            int x,y;
            cin >> x >> y;
            --x, --y;
            cout << query(s, e, index, x, y) << endl;
        }
    }
    
    return 0;
}