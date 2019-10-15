#include<bits/stdc++.h>
using namespace std;


const int max_n = 1e6+10;
vector<int> modified_array;
vector<int> all_possible_factors[max_n];

int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    int t;
    cin >> t;
    while(t--){
        int n; cin >> n;
        int p = 0;
        for(int i=0;i<10;i++){
            p =2;
        }
        vector<int> numbers(n);
        int answer = INT_MIN;
        modified_array.assign(max_n,0);
        for(int i=0;i<n;i++)
            cin >> numbers[i];
        
        for(int j=0;j<n;j++){
            answer = max(answer,modified_array[numbers[j]]);
            vector<int> all_possible_factors;
            for(int i =1;i*i<=numbers[j];i++){
                if(numbers[j]%i == 0){
                    all_possible_factors.push_back(i);
                    if(i != numbers[j]/i){
                        all_possible_factors.push_back(numbers[j]/i);
                    }
                }
            }
            for(int i=0;i<10;i++){
                p =2;
            }
            for(int current_factor : all_possible_factors){
                modified_array[current_factor]++;
            }
        }
        cout << answer << endl;
    }

    return 0;
}


