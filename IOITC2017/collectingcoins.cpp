#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 1003, inf = 1e12;
const int mxc = 30 * 1000 + 2;
vector<array<int, 2>> g[mxn];
int n, d, dp[mxn][mxc], c[mxn], dp1[mxc], sz[mxn];

void dfs(int v, int p) {
    dp[v][0] = dp[v][c[v]] = 0;
    sz[v] = c[v];
    for(auto tx : g[v]) {
        int u = tx[0], w = tx[1];
        if(u == p) continue;
        dfs(u, v);
        for(int i = 0; i <= sz[v] + sz[u]; i++)
            dp1[i] = inf;
        dp1[0] = 0; dp1[c[v]] = 0;
        for(int i = 0; i <= sz[v]; i++)
            for(int j = 0; j <= sz[u]; j++) {
                dp1[i + j] = min(dp1[i + j], dp[v][i] + w + dp[u][j]);
            }
        sz[v] += sz[u];
        for(int i = 0; i <= sz[v]; i++)
            dp[v][i] = min(dp[v][i], dp1[i]);
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
    cin >> n >> d;
    for(int i = 1; i <= n; i++)
    	cin >> c[i];
    for(int u, v, w, i = 1; i < n; i++) {
    	cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	g[v].push_back({u, w});
    }
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < mxc; j++)
            dp[i][j] = inf;
    dfs(1, -1);
    int ans = 0;
    for(int i = sz[1]; i >= 0; i--) {
        if(2 * dp[1][i] <= d) {
            ans = i; break;
        }
    }
    cout << ans << '\n';
    return 0;
}