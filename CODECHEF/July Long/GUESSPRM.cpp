#include<bits/stdc++.h>
#pragma GCC optimize("O3","Ofast")
using namespace std;

template<class T> ostream& operator<<(ostream &os,vector<T> V){os<<"[ ";for(auto v:V)os<<v<<" ";return os<<"]";}
template<class L,class R> ostream& operator<<(ostream &os,pair<L,R> P){return os<<"("<<P.first<<","<<P.second<<")";}
#define DEBUG1(x) cout  << '>' << " " << #x << ':' << " " <<  x << endl;
#define DEBUG2(x,y) cout  << '>' << " " << #x << ':' << " " <<  x <<  " " << #y << ':' << " " <<  y <<endl;
#define DEBUG3(x,y,z) cout  << '>' << " " << #x << ':' << " " <<  x << " " << #y << ':' << " " <<  y <<" " << #z << ':' << " " <<  z << " " <<endl;
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


const int mod = 10*9+7;
const int inf = 2e9;
const LL linf = 2e18;
const double eps = 1e-9;

/////////////////////////////

LL randgen(){
    LL a = rand() % (1 << 15);
    LL b = rand() % (1 << 15);
    LL c = (1 << 15) * a + b;
    return c;
}
bool isprime(LL x){
    for (LL i = 2; i * i <= x;i++){
        if(x%i == 0){
            return 0;
        }
    }
    return 1;
}
void fact(LL x,vector<LL> &nums){
    for (LL i = 2; i * i <= x;i++){
        if(x% i == 0){
            if(isprime(i))
                nums.PB(i);
            if(i*i != x){
                if(isprime(x/i))
                    nums.PB(x / i);
            }
        }
    }
    sort(ALL(nums));
}

int query(LL x){
    cout << "1 " << x << endl;
    LL a;
    cin >> a;
    return a;
}

void reply(LL x){
    cout << "2 " << x << endl;
    string a;
    cin >> a;
}

void solve(){
    LL  n = 1000 * 1000;
    LL rem = query(n);
    n = n * n - rem;
    vector<LL> nums;
    set<int> mods;
    
    fact(n, nums);
    cout << nums << endl;
    BACK1:
    LL random = randgen();
    //DEBUG1(random);
    for (LL cc : nums){
        mods.insert((random * random) % cc);
    }
    if(mods.size() == nums.size()){
        map<LL, LL> m1;
        for (LL i = 0;i<nums.size();i++){
            m1[(random*random)%nums[i]] = nums[i];
            DEBUG2((random * random) % nums[i], nums[i]);
        }
        LL rem2 = query(random);
        reply(m1[rem2]);
    }else{
        
        //vector<int> garbage(mods.begin(), mods.end());
        //cout << garbage << endl;
        mods.clear();
        goto BACK1;
    }
    cout << endl;
}
int main(){
    freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
    //srand (time(NULL));
    int t;
    cin >> t;
    while(t--){
        solve();
    }

}