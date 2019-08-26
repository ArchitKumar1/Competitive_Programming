#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define TC int t; cin>>t; while(t--)
#define rep(i,n) for(int i=0;i<n;i++)
#define fastio ios_base::sync_with_stdio(false); cin.tie(0);

int mindist(int dist[],bool splset[],int V){
	int mi = INT_MAX, min_index;

   for (int v = 0; v < V; v++)
     if (splset[v] == false && dist[v] <= mi)
         mi = dist[v], min_index = v;

   return min_index;
}

int main(){
	int V=9;
	int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                      {4, 0, 8, 0, 0, 0, 0, 11, 0},
                      {0, 8, 0, 7, 0, 4, 0, 0, 2},
                      {0, 0, 7, 0, 9, 14, 0, 0, 0},
                      {0, 0, 0, 9, 0, 10, 0, 0, 0},
                      {0, 0, 4, 14, 10, 0, 2, 0, 0},
                      {0, 0, 0, 0, 0, 2, 0, 1, 6},
                      {8, 11, 0, 0, 0, 0, 1, 0, 7},
                      {0, 0, 2, 0, 0, 0, 6, 7, 0}
                     };
	int src=0;
	int dist[V];
	bool splset[V]={0};
	for (int i = 0; i < V; i++) dist[i] = INT_MAX;
	dist[src]=0;
	for(int i=0;i<V-1;i++){
		int u=mindist(dist,splset,V);
		splset[u]=true;
		for(int v=0;v<V;v++){
			if (!splset[v] && graph[u][v] && dist[u] != INT_MAX && dist[u]+graph[u][v] < dist[v])
            dist[v] = dist[u] + graph[u][v];
		}
	}

	for(int i=0 ;i < V ;i++){
		cout<< i << " " << dist[i] << " "<<endl;
	}
	return 0;
}
