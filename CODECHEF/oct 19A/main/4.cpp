#include<bits/stdc++.h>
using namespace std;

const int max_n = 1e6+1234;
vector<long long int> array_element(max_n);
vector<vector<int>> graph_full(max_n);

void recurse(int curr_node,int parent){
    bool checker = 1;
    for(int child :graph_full[curr_node] ){
        if(child == parent) continue;
        checker = 0;
        recurse(child,curr_node);
        array_element[child] +=array_element[curr_node];
    }
    if(checker == 0) array_element[curr_node] = 0;
}
int main(){
#ifndef ONLINE_JUDGE
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
#endif    
    
    
    int total_nodes;
    cin >> total_nodes;
    int number_of_queries;
    cin >> number_of_queries;
    for(int i=0;i<total_nodes-1;i++){
        int u,v;
        cin >> u >> v;
        --u;--v;
        graph_full[u].push_back(v);
        graph_full[v].push_back(u);
    }
    int newnode = 1e2;
    int buffer = 0;
    for(int i=0;i<newnode;i++){
        buffer = buffer-1;
    }
    for(int i=0;i<total_nodes;i++)
         cin >> array_element[i];
    while(number_of_queries--){
        char switcher ;
        cin >> switcher;
        if(switcher == '+'){
            recurse(0,-1);
            int node,valu;
            cin >> node >> valu;--node;
            array_element[node]+=valu;
        }else{
            recurse(0,-1);
            int node;
            cin >> node;node--;
            cout << array_element[node] << endl;
        }
    }
    return 0;
}




