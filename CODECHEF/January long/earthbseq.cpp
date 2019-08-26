#include<bits/stdc++.h>
using namespace std;
#define ll long long int
const int N = (int)1e6 + 1;
int primes[N];
vector<int> prim;

void seive(){
    for (int i = 2; i < N - 1;i++){
        if(primes[i] == 1){
            prim.push_back(i);
            for (int j = i; j < N - 1;j = j + i){
                primes[j] = 0;
            }
        }
    }
}
int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output1.txt", "w", stdout);
#endif
    for (int i = 0; i < N;i++){
        primes[i] = 1;
    }
    seive();
    for (int i = 0; i < 20;i++){
        cout << prim[i] << " ";
    }
    // int t;
    // cin >> t;
    // while(t--){
    //     int n;
    //     cin >> n;
    //     int temp[3] = {6, 10, 15};
    //     int j = 0;
    //     int i = 4;
    //     int cnt = 0;
    //     while(cnt++ < n-1){
    //         cout << (ll) prim[i++] * temp[j] << " ";
    //         j = (j + 1) % 3;
    //     }
    //     cout << prim[i - 1] * 11;
    //     cout << endl;
    // }
#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;
}