#include<bits/stdc++.h>
using namespace std;
map<string, int> m1;

int lpss(string a,int i,int j){   
    if(i>j) return 0;
    if(i == j)  return 1;
    string temp = to_string(i) + ":" + to_string(j);
    if(m1[temp] == 0) {
        if(a[i] == a[j]) m1[temp] = 2 + lpss(a,i+1,j-1);
        else m1[temp] = max(lpss(a,i+1,j),lpss(a,i,j-1));
    }
    return m1[temp];
}
int lpst(string a,int i,int j){   
    if(i>j) return 0;
    if(i == j)  return 1;
    string temp = to_string(i) + ":" + to_string(j);
    if(m1[temp] == 0) {
        if(a[i] == a[j]) m1[temp] = 2 + lpst(a,i+1,j-1);
        else
            m1[temp] = 0;
    }
    return m1[temp];
}
string longestPalindrome(string A) {
    int N = A.size();
    vector<vector<bool> > P(N+1, vector<bool>(N+1, true));
    int start = 0, len = 1;
    
    for (int k = 1; k < N; ++k) {
        for (int i = 1; i <= N-k; ++i) {
            P[i][i+k] = P[i+1][i+k-1] && (A[i-1] == A[i+k-1]);
            if (P[i][i+k] && k+1 > len)
                start = i-1, len = k+1;
        }
    }
    
    string result(A.begin() + start, A.begin() + start + len);
    return result;
}
int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

    string a = "abccssshjgjhghjgjh";
    cout << longestPalindrome(a) << endl;

    return 0;
}
