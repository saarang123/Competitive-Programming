#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 3, lgn = 19;
int tin[mxn], tout[mxn], bit[mxn], up[mxn][lgn], info[mxn], last[mxn];
bool active[mxn];
vector<int> g[mxn];
int n, m, q, tx = 1;
 
void upd(int x, int v) {
	for(; x <= n; x += (x & -x))
		bit[x] += v;
}
 
int qry(int x) {
	int res = 0;
	for(; x; x -= (x & -x))
		res += bit[x];
	return res;
}
 
void dfs(int v, int p = 0) {
	up[v][0] = p;
	info[v] = 1;
	tin[v] = tx++;
	for(int i = 1; i < lgn && up[v][i - 1]; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for(int u : g[v]) if(u != p) dfs(u, v);
	tout[v] = tx;
}
 
int find_root(int u) {
	int lca = u, path = qry(tin[u]);
	for(int i = lgn - 1; ~i; i--)
		if(up[lca][i] && qry(tin[up[lca][i]]) == path) 
			lca = up[lca][i];
	return lca;
}
 
signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m >> q;
    vector<array<int, 2>> edge(n - 1);
    for(auto &[u, v] : edge) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1);
    for(int i = 1; i <= n; i++) {
    	upd(tin[i], -1);
    	upd(tout[i], 1);
    }
    while(m--) {
    	int idx; cin >> idx; idx--;
    	int u = edge[idx][0], v = edge[idx][1];
    	if(up[u][0] == v)
    		swap(u, v);
    	if(active[idx]) {
    		info[v] = last[v] = info[find_root(u)];
    		upd(tin[v], -1);
    		upd(tout[v], 1);
    	} else {
    		info[find_root(u)] += info[v] - last[v];
    		upd(tin[v], 1);
    		upd(tout[v], -1);
    	}
    	active[idx] ^= 1;
    }
    while(q--){
    	int u; cin >> u;
    	cout << info[find_root(u)] << '\n';
    }
    return 0;
}

