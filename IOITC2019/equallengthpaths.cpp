#include <bits/stdc++.h>
using namespace std;
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
    vector<array<int, 2>> ed(m);
    vector<bool> vis(n + 1), done(m);
    vector<vector<array<int, 2>>> g(n + 1);
    for(int i = 0; i < m; i++) {
    	cin >> ed[i][0] >> ed[i][1];
    	g[ed[i][0]].push_back({ed[i][1], i});
    	g[ed[i][1]].push_back({ed[i][0], i});
    }
    function<void(int v)> dfs = [&] (int v) {
    	vis[v] = true;
    	for(auto tx : g[v]) {
    		int u = tx[0], id = tx[1];
    		if(!done[id]) 
    			ed[id] = {u, v};
    		done[id] = true;
    		if(!vis[u])
    			dfs(u);
    	}
    };
    dfs(1);
    for(auto tx : ed)
    	cout << tx[0] << ' ' << tx[1] << '\n';
    return 0;
}