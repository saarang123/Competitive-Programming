#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 3;
vector<int> g[mxn];
int n, ans, dt[mxn];

int dfs(int v = 1, int p = -1) {
	int mx = 0;
	for(int u : g[v]) if(u != p) {
		dt[u] = dt[v] + 1;
		int cur = 1 + dfs(u, v);
		ans = max(ans, mx + cur);
		mx = max(mx, cur);
	}
	return mx;
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n;
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs();
    cout << ans << '\n';
    return 0;
}