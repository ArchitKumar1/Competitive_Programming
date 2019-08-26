#include<bits/stdc++.h>
using namespace std;
#define LL long long int
const LL N = 123456789;
vector<LL> prime(N,1);
vector<LL> all;

void seive(){
    for(LL i=2;i*i<=N;i++){
        if(prime[i] == 1){
            for(LL j = i*i;j<N;j = j+i){
                prime[j] =0;
            }
        }
    }
    for(int i=2;i<N;i++){
        if(prime[i] == 1){
            all.push_back(i);
        }
    }
}
int main(){
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
    seive();
    long long n ;
    cin >> n;
    bool ok = 1;
    if(all[all.size()-1] *all[all.size()-1] < n){
        cout << "NOPE";
        exit(0);
    }
    for(LL c : all){
        if(n%c == 0){
            cout << "non- prime" << endl;
            exit(0);
        }
    }
    cout << "prime " << endl;
    return 0;

}