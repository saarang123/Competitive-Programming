#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 3e5 + 3;
vector<int> g[MXN];
int dt[MXN], n, k;
long long dp[MXN], cnt[MXN], ans[MXN];
bool is[MXN];

int dfs(int v = 1, int p = -1) {
	dp[v] = 0;
	cnt[v] = is[v];
	for(int u : g[v]) if(u != p) {
		dt[u] = dt[v] + 1;
		dp[v] += dfs(u, v) + cnt[u];
		cnt[v] += cnt[u];
	}
	return dp[v];
}

void reroot(int v = 1, int p = -1) {
	ans[v] = dp[v];
	for(int u : g[v]) if(u != p) {
		dp[v] -= (dp[u] + cnt[u]);
		cnt[v] -= cnt[u];
		dp[u] += dp[v] + cnt[v];
		cnt[u] += cnt[v];
		reroot(u, v);
		cnt[u] -= cnt[v];
		dp[u] -= (dp[v] + cnt[v]);
		cnt[v] += cnt[u];
		dp[v] += dp[u] + cnt[u];
	}
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n;
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    cin >> k;
    for(int x, i = 0; i < k; i++) {
    	cin >> x;
    	is[x] = true;
    }
    dfs();
    reroot();
    // for(int i = 1; i <= n; i++)
    // 	cout << dt[i] << " \n"[i == n];
    // for(int i = 1; i <= n; i++)
    // 	cout << dp[i] << " \n"[i == n];
    // for(int i = 1; i <= n; i++)
    // 	cout << ans[i] << " \n"[i == n];
    int mn = *min_element(ans + 1, ans + n + 1);
    int c = 0;
    for(int i = 1; i <= n; i++)
    	c += ans[i] == mn;
    cout << c << ' ' << mn << '\n';
    return 0;
}