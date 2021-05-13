#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 3;
const long long inf = 1e17;
vector<int> g[mxn];
int n, x, y, dp[mxn][3];

void dfs(int v = 1, int p = -1) {
	dp[v][1] = dp[v][2] = -mxn;
	for(int u : g[v]) if(u != p) {
		dfs(u, v);
		dp[v][2] = max({dp[v][2], dp[v][2] + max({dp[u][0], dp[u][1], dp[u][2]}), dp[v][1] + 1 + max(dp[u][0], dp[u][1])});
		dp[v][1] = max({dp[v][1], dp[v][1] + max({dp[u][0], dp[u][1], dp[u][2]}), dp[v][0] + 1 + max(dp[u][0], dp[u][1])});
		dp[v][0] = max(dp[v][0], dp[v][0] + max({dp[u][0], dp[u][1], dp[u][2]}));
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
    cin >> n >> x >> y;
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    if(x >= y) {
    	long long ans = ((long long) n - 1) * y;
    	for(int i = 1; i <= n; i++) if(g[i].size() == n - 1)
    		ans = ((long long) n - 2) * y + x;
    	return cout << ans << '\n', 0;
    }
    dfs();
    long long ans = max({dp[1][0], dp[1][1], dp[1][2]});
    cout << x * ans + (n - 1 - ans) * y << '\n';
    return 0;
}