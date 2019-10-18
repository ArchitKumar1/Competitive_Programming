#include<bits/stdc++.h>
using namespace std;
 
template<class T> ostream& operator<<(ostream &os,vector<T> V){
    os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";
}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){
    return os<<"("<<P.first<<","<<P.second<<")";
}
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__,__VA_ARGS__)
template<typename Arg1>
void __f(const char* name,Arg1&& arg1){
	cout<<name<<" : "<<arg1<<endl;
}
template<typename Arg1,typename... Args>
void __f(const char* names,Arg1&& arg1,Args&&... args){
		const char* comma=strchr(names+1,',');cout.write(names,comma-names)<<" : "<<arg1<<" | ";__f(comma+1,args...);
}
#else
#define trace(...) 1
#endif
 
#define FASTIO ios_base::sync_with_stdio(false); cin.tie(NULL);
#define TC int t; cin >> t;while(t--)
#define forn(i,n) for(int i=0;i<n;i++)
 
#define ALL(x) x.begin(),x.end()
#define LL long long int
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define endl "\n"
 
typedef pair<int,int>PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<PII> VPII;
 
const int mod = pow(10,9) +7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;
 
 
/////////////////////////////

int min(int a, int b) 
{ 
    int res = a; 
    if(b < a) 
        res = b; 
    return res; 
} 
  
int findLongestPalindromicString(string text) 
{ 
    int N = text.length(); 
    if(N == 0) 
        return 0; 
    N = 2*N + 1; //Position count 
    int L[N]; //LPS Length Array 
    L[0] = 0; 
    L[1] = 1; 
    int C = 1; //centerPosition  
    int R = 2; //centerRightPosition 
    int i = 0; //currentRightPosition 
    int iMirror; //currentLeftPosition 
    int maxLPSLength = 0; 
    int maxLPSCenterPosition = 0; 
    int start = -1; 
    int end = -1; 
    int diff = -1; 
      
    //Uncomment it to print LPS Length array 
    //printf("%d %d ", L[0], L[1]); 
    for (i = 2; i < N; i++)  
    { 
        //get currentLeftPosition iMirror for currentRightPosition i 
        iMirror  = 2*C-i; 
        L[i] = 0; 
        diff = R - i; 
        //If currentRightPosition i is within centerRightPosition R 
        if(diff > 0) 
            L[i] = min(L[iMirror], diff); 
  
        //Attempt to expand palindrome centered at currentRightPosition i 
        //Here for odd positions, we compare characters and  
        //if match then increment LPS Length by ONE 
        //If even position, we just increment LPS by ONE without  
        //any character comparison 
        while ( ((i + L[i]) < N && (i - L[i]) > 0) &&  
            ( ((i + L[i] + 1) % 2 == 0) ||  
            (text[(i + L[i] + 1)/2] == text[(i - L[i] - 1)/2] ))) 
        { 
            L[i]++; 
        } 
  
        if(L[i] > maxLPSLength)  // Track maxLPSLength 
        { 
            maxLPSLength = L[i]; 
            maxLPSCenterPosition = i; 
        } 
  
        //If palindrome centered at currentRightPosition i  
        //expand beyond centerRightPosition R, 
        //adjust centerPosition C based on expanded palindrome. 
        if (i + L[i] > R)  
        { 
            C = i; 
            R = i + L[i]; 
        } 
        //Uncomment it to print LPS Length array 
        //printf("%d ", L[i]); 
    } 
    //printf("\n"); 
    start = (maxLPSCenterPosition - maxLPSLength)/2; 
    end = start + maxLPSLength - 1; 
    return end-start + 1;
} 

int main(){
 FASTIO    
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif  
string text;
    cin >> text;
    int n = text.length();
    int ans =0 ;
    for(int i=0;i<n;i++){
        trace(text.substr(0,i+1),text.substr(i+1,n-i));
        int ans1  = findLongestPalindromicString(text.substr(0,i+1)) ;
        cout << ans << endl;
        int ans2 =  findLongestPalindromicString(text.substr(i+1,n-i));
        cout << ans << endl;

    }
    cout << ans << endl;
    return 0;
}

