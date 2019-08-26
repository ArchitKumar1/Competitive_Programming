#include<bits/stdc++.h>
using namespace std;
#define ll long long int

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

    int n;
    double t;
    cin >> n >> t;
    double temp = 1e8;
    double d[n], v[n];
    for (int i = 0; i < n;i++){
        cin >> d[i] >> v[i];
        temp = min(v[i], temp);
    }
    double high = 1e10;
    double low = -1.0 * temp;
    for (int i = 0; i < 5000;i++){
        double mid = high / 2 + low / 2;
        double sum = 0.0;
        for (int i = 0; i < n;i++){
            sum += d[i] / (v[i] + mid);
        }
        if(sum < t){
            high = mid;
        }else{
            low = mid;
        }
    }
    cout.precision(10);
    cout << (high +low)/ 2 << endl;

#ifndef ONLINE_JUDGE
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC * 1000 << " ms." << endl;
#endif
    return 0;

}