#include <bits/stdc++.h>
using namespace std;
const int mxn = 100 * 1000 + 3;
set<array<int, 2>> g[mxn];
array<int, 3> dp[mxn];
array<int, 2> maxdt[mxn];

void dfs(int v = 1, int p = -1) {
	array<int, 2> best = {0, 0}, next = {0, 0};
	for(auto &[u, e] : g[v]) if(u != p) {
		dfs(u, v);
		if(maxdt[u][0] + e > best[0]) {
			next = best;
			best = {maxdt[u][0] + e, u};
		} else if(maxdt[u][0] + e > next[0]) {
			next = {maxdt[u][0] + e, u};
		}
	}
	maxdt[v] = best;
	dp[v] = {best[0] + next[0], best[1], next[1]};
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    int n, k;
    cin >> n >> k;
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].insert({v, 1});
    	g[v].insert({u, 1});
    }

    dfs();
    if(k == 1)
    	return cout << 2 * (n - 1) + 1 - (*max_element(dp + 1, dp + n + 1))[0], 0;
    int root = max_element(dp + 1, dp + n + 1) - dp;
    int ans = dp[root][0];

    for(int v = root, u = dp[root][1]; u; v = u, u = maxdt[u][1]) {
    	g[v].erase({u, 1});
    	g[v].insert({u, -1});
    }
    for(int v = root, u = dp[root][2]; u; v = u, u = maxdt[u][1]) {
    	g[v].erase({u, 1});
    	g[v].insert({u, -1});
    }

    dfs();
    cout << 2 * (n - 1) + 2 - ans - (*max_element(dp + 1, dp + n + 1))[0];
    return 0;
}