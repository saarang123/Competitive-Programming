#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 4;
bool bridge = false;
vector<int> g[mxn];
int tin[mxn], low[mxn], tx;
vector<array<int, 2>> edges;

void dfs(int v, int p) {
	tin[v] = low[v] = ++tx;
	for(int u : g[v]) if(u != p) {
		if(tin[u] == -1) {
			edges.push_back({v, u});
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if(low[u] > tin[v])
				bridge = true;
		} else if(tin[u] < tin[v]) {
			edges.push_back({v, u});
			low[v] = min(low[v], tin[u]);
		}
	}
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
    memset(tin, -1, sizeof tin);
    for(int u, v, _ = 0; _ < m; _++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1, -1);
    if(bridge)
    	return cout << 0 << '\n', 0;
    for(auto &[u, v] : edges)
    	cout << u << ' ' << v << '\n';
    return 0;
}