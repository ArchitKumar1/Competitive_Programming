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
#define REP(i,a,b) for(int i = a;i<=b;i++)

#define ALL(x) x.begin(),x.end()
#define LL long long int
#define PB push_back
#define EB emplace_back
#define F first
#define S second
#define endl "\n"
/////////////////////////////
const int N = 1234;
map<pair<int,string>,vector<int>>m1[N];


void helper(map<int,int> &m1,LL num){
    for(int i=2;i*i<=num;i++){
        int cnt =0 ;
        while(num%i == 0){
            cnt++;
            num = num/i;
        }
        if(cnt){
            m1[i] += cnt;
        }
    }
    if(num!=1){
        m1[num] +=1;
    }
}

void eval(int base,string num){
    map<int,int> m1;
    int res = 0;
    int pos = 0;
    for(int i = num.size()-1;i>=0;i--){
        char c = num[i];
        int t = 0;
        if(c >='A' && c <='Z'){
            t = 10 + (int) ( c - 'A');
        }else{
            t = (int)(c -'0');
        }
        //res += t * pow(base,pos);
        if(t!=0){
            helper(m1,t);
            forn(k,pos){
                helper(m1,base);
            }
        }
        
        pos++;
    }
    vector<pair<int,int>> every(ALL(m1));
    trace(every);
    return;
    //
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    

    eval(2,"1010");
    return 0;
}




