#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define FORE(i,a,b) for(int i=a;i<=b;i++)
#define RFORE(i,a,b) for(int i=a;i>=b;i--)
#define v vector
typedef long long ll;
typedef pair<int, int > pii;
typedef array<int,3> tri;

clock_t begin_time;


void dfs(int x, v<bool> &vis, v<v<int>> &adj, v<int> &comp){
	if(vis[x]) return;
	vis[x] = true;
	comp.push_back(x);
	for(auto y : adj[x]) dfs(y, vis, adj, comp);
}

int mx;

int build(v<int> nodes, v<tri> conds, v<int> &par){
//	cout << "---- Build ----\n";
//	cout << "nodes:: ";
//	for(auto i : nodes) cout << i << ", ";
//	cout << "\n";
//	cout << "conditions:: ";
//	for(auto c : conds) cout << "(a=" << c[0] << ", b=" << c[1] << ", lca=" << c[2] << "), ";
//	cout << "\n";
	int time = (int)(float(clock() - begin_time) / CLOCKS_PER_SEC * 1000);
	if(time>100) return -1;

	if(nodes.size()==1){
		return nodes[0];
	}

	v<int> conv(mx);
	FOR(i,0,nodes.size())
		conv[nodes[i]] = i;
	
	v<bool> pos_root(nodes.size(), true);
	for(auto &x : conds){
		if(x[0]!=x[2])
			pos_root[conv[x[0]]] = false;
		if(x[1]!=x[2])
			pos_root[conv[x[1]]] = false;
	}

	FOR(i,0,nodes.size()) if(pos_root[i]){
		int root = nodes[i];
//		cout << "root at " << root << "\n";

		v<v<int>> adj(nodes.size(), v<int>());
		for(auto &c : conds) if(c[2]!=root){
			adj[conv[c[2]]].push_back(conv[c[0]]);
			adj[conv[c[0]]].push_back(conv[c[2]]);
			adj[conv[c[2]]].push_back(conv[c[1]]);
			adj[conv[c[1]]].push_back(conv[c[2]]);
		}
		v<v<int>> comps;
		v<bool> vis(nodes.size(), false);
		FOR(j,0,nodes.size()) if(!vis[j] && j!=i){
			comps.push_back(v<int>());
			dfs(j, vis, adj, comps.back());
		}
		v<int> which_comp(nodes.size());
		FOR(c,0,comps.size()) for(auto x : comps[c])
			which_comp[x] = c;
		which_comp[i] = -1;

//		cout << "nodes: ";
//		FOR(x,0,nodes.size()) cout << nodes[x] << " ";
//		cout << "\n";
//		cout << "comps: ";
//		FOR(x,0,nodes.size()) cout << which_comp[x] << " ";
//		cout << "\n";


		bool root_good = true;
		for(auto &c : conds) if(c[2]==root){
			if(which_comp[conv[c[0]]]==which_comp[conv[c[1]]]){
				root_good = false;
				break;
			}
		}
		if(!root_good) continue;


		FOR(x,0,comps.size())FOR(y,0,comps[x].size())
			comps[x][y] = nodes[comps[x][y]];
		v<v<tri>> nex_cond(comps.size(), v<tri>());
		for(auto &c : conds) if(c[2]!=root){
//			if(!(c[0]!=root && c[1]!=root)){
//				cout << "FUUCK: c[0]!=root && c[1]!=root \n";
//				exit(0);
//			}
			int w0 = which_comp[conv[c[0]]];
			int w1 = which_comp[conv[c[1]]];
			int w2 = which_comp[conv[c[2]]];
//			if(!(w0==w1 && w1==w2)){
//				cout << "FUUCK w0==w1 && w1==w2\n";
//				cout << "condition: " << c[0] << c[1] << c[2] << "\n";
//				exit(0);
//			}
			nex_cond[w0].push_back(c);
		}


		FOR(x,0,comps.size()){
			int res = build(comps[x], nex_cond[x], par);
			if(res==-1){
				root_good = false;
				break;
			}
			par[res] = root;
		}

		if(root_good){
			return root;
		}
	}
	return -1;
}
void solve(){
//	cout << "\n";
	begin_time = clock();
	int N, M;
	cin >> N >> M;
	v<int> nodes(N);
	FOR(i,0,N) nodes[i] = i+1;
	v<tri> conds(M, {0,0,0});
	FOR(i,0,M) cin >> conds[i][0] >> conds[i][1] >> conds[i][2];
	v<int> par(N+1, 0);
	mx = N+1;
	
	int res = build(nodes, conds, par);
	if(res==-1) {
//		cout << "-1 ";
		cout << "Impossible";
	} else{
//		cout << "69 ";
		FORE(i,1,N-1) cout << par[i] << " ";
		cout << par[N];  
	}
	cout << "\n";
}

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	freopen("d_in.txt", "r", stdin); freopen("d_out.txt", "w", stdout);
	int tc; cin >> tc;
	FORE(i,1,tc){
		cout << "Case #" << i << ": ";
		solve();
	}
}