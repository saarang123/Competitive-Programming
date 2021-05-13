#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 2;
vector<int> g[mxn], gt[mxn];
vector<int> order, comp;
vector<bool> used;
vector<vector<int>> scc;

void dfs(int v) {
	used[v] = true;
	for(int u : g[v])
		if(!used[u])
			dfs(u);
	order.push_back(v);
}

void fin(int v) {
	used[v] = true;
	comp.push_back(v);
	for(int u : gt[v]) 
		if(!used[u])
			fin(u);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    for(int u, v, i = 0; i < m; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	gt[v].push_back(u);
    }
    used.assign(n + 1, false);
    for(int i = 1; i <= n; i++)
    	if(!used[i])
    		dfs(i);
    reverse(order.begin(), order.end());
    used.assign(n + 1, false);
    for(int v : order)
    	if(!used[v]) {
    		fin(v);
    		scc.push_back(comp);
    		comp.clear();
    	}
    if(scc.size() == 1)
    	cout << "YES\n";
    else
    	cout << "NO\n" << scc[1][0] << ' ' << scc[0][0] << '\n';
    return 0;
}