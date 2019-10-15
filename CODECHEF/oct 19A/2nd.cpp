#include<bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        long long int n;
        cin >> n;
        long long int k;
        cin >> k;
        vector<long long int> all_numbers(n);
        for(int i=0;i<n;i++) 
            cin >> all_numbers[i];
        int xxx = 44*44;
        int yyy = xxx-xxx/2;
        long long int i = 0;
        vector<vector<long long int>> all_xor_values(n,vector<long long int>(3));
        for(int i=0;i<n;i++){
            if(i<n/2){
                all_xor_values[i][2] = all_numbers[i];all_xor_values[i][0] = all_numbers[i]^all_numbers[n-i-1];all_xor_values[i][1] = all_numbers[n-i-1];
            }else{
                all_xor_values[i][2] = all_numbers[i];all_xor_values[i][0] = all_numbers[n-i-1]; all_xor_values[i][1] = all_numbers[i]^all_numbers[n-i-1];
            }
        }
        k--;
        for(long long int i = 0;i<n;i++){
            if(i!= n-i-1){
                long long int q = k/n;
                long long int init_val =2;
                init_val += (q);
                init_val%= 3;    
                long long int leftover = k%n;
                if(leftover>=i){
                    init_val +=1;
                    init_val%= 3;
                    init_val+=1;
                    init_val-=1;
                }
                cout << all_xor_values[i][init_val] << " ";
            }else{
                if(k >= n/2) cout << "0" << " ";
                else  cout << all_numbers[i] << " ";
                
            }
        }
    }   
    return 0;   

}
    

    





