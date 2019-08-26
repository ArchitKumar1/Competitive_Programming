#include<bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
#define LL long long int
#define PB push_back
#define EB emplace_back
#define FI first
#define SE second
#define endl "\n"
typedef pair<int,int>PII;
typedef pair<PII,int> PPIII;
typedef pair<int,PII> PIPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<PII> VPI;
const int mod = 10*9+7;
const int inf = 2e9;
const LL linf = 2e18;

const int N = 123456;
const int M = 123;
vector<vector<vector<int>>> free1(M, vector<vector<int>>(M, vector<int>(M, 0)));
vector<int> in_time_node_count,out_time_node_count;
vector<vector<int>> binarylift;
vector<int> mark;
vector<int> graph_edges[N];
vector<int> kiddoinverse;
int basic_property = 0;
int fans = 0;

void pre(){
    for (int i = 0; i < M;i++){
        for (int j = 0; j < M;j++){
            for (int k = 0; k < M;k++){
                free1[i][j][k] = i + j + k + rand()%10;
            }
        }
    }
}
bool related(int u, int v){
    return in_time_node_count[u] <= in_time_node_count[v] && out_time_node_count[u] >= out_time_node_count[v];
}
void findpath(int start,int end,int CommonPoint,vector<int> &Graph_Path){
    vector<int> left,right;
    if(start != CommonPoint)for(int i = start;i!=CommonPoint;i = kiddoinverse[i])left.PB(i);
    if(end != CommonPoint)for(int i = end;i!=CommonPoint;i = kiddoinverse[i])right.PB(i);
    reverse(right.begin(),right.end());
    for(int node : left) Graph_Path.PB(node);
    Graph_Path.PB(CommonPoint);
    for(int node : right) Graph_Path.PB(node);
}

int ShortestCommonPoint(int start, int end){
    if (related(start, end)) return start;
    if (related(end, start)) return end;
    for (int i = 20; i >= 0; --i)  if (!related(binarylift[start][i], end)) start = binarylift[start][i];
    return binarylift[start][0];
}
void preliminarydepthfirstsearch(int s, int par)
{
    in_time_node_count[s] = ++basic_property;
    binarylift[s][0] = par;
    kiddoinverse[s] = par;
    for (int i = 1; i <= 20; ++i)
        binarylift[s][i] = binarylift[binarylift[s][i-1]][i-1];
    for(int c : graph_edges[s]){
        if (c == par) continue;
        preliminarydepthfirstsearch(c,s);
    }
    out_time_node_count[s] = ++basic_property;
}

void checkernodenounter(int s,int par,int &flagger){
    ++fans;++flagger;
    for(int c : graph_edges[s]){
        if(c == par) continue;
        checkernodenounter(c,s,flagger);
    }
}
void helper2(int s,int e,int ss,int ee,int flag1){
    vector<vector<int>> dp(M,vector<int>(M,0));
    dp[0][0] = s;
    dp[0][1] = e;
    dp[0][2] = ss;
    dp[0][3] = ee;
    dp[0][4] = flag1;
    vector<vector<vector<int>>> dp_bit_mask(M, vector<vector<int>>(M, vector<int>(M, -2)));
    int nn = 1e5 + 100;
    vector<int> arr(nn,0);
    vector<vector<int>> fpp_pitch;
    fpp_pitch.assign(10, vector<int>(10, 0));
}
void helpme(vector<int> Graph_Path){
    list<int> templist;
    templist.PB(-1);
    for(int xxyy : Graph_Path){
        templist.PB(xxyy);
    }
    templist.PB(-1);
    vector<int> templist1(templist.begin(),templist.end());
    for(int i = 1;i< (int) templist.size() -1;i++){
        ++fans;
        vector<int> basicflow;
        int flagger1 =0;
        for(int c : graph_edges[templist1[i]]){
            if(c !=templist1[i-1] && c!= templist1[i+1]){                  
                checkernodenounter(c,templist1[i],flagger1);
                basicflow.PB(flagger1);
                flagger1 = 0;
            }
        }
        int temptotal = 0,tempcounter = 0;
        for(int xc : basicflow){
            temptotal += tempcounter * xc;
            tempcounter += xc;
        }
        fans +=temptotal;
        basicflow.clear();
    }
}
void solve(){
    int number;cin >>number;
    int queries; cin >>queries;   
    for(int i=0;i<number-1;i++){
        int x,y;cin >> x >> y;x--;y--;
        graph_edges[x].PB(y);
        graph_edges[y].PB(x);
    }
    in_time_node_count.assign(number,0);
    out_time_node_count.assign(number,0);
    kiddoinverse.assign(number,0);
    binarylift.assign(number,vector<int>(50,0));
    preliminarydepthfirstsearch(0,0);
    while(queries--){
        int xx,yy;
        int cd = 0;
        cin >> xx >> yy;
        vector<int> Graph_Path;
        --xx,--yy;
        cd++;
        cd = cd * cd;
        int solsol = ShortestCommonPoint(xx,yy);
        findpath(xx,yy,solsol ,Graph_Path);
        helpme(Graph_Path);
        cout << fans << endl;
        fans = 0;
        Graph_Path.clear();        
    }
    for(int i=0;i<number;i++){
        graph_edges[i].clear();
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        pre();
        solve();
    }
    return 0;
}