#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int MXN = 53, MXL = 55000 + 3;
ll dp[MXN][MXL][2];
ll gift[MXN][MXL], c[MXN];
vector<array<int, 2>> g[MXN], rev[MXN];
int n, m, k, l;
ll ans = 0;

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    cin >> n >> m >> l >> k;
    memset(dp, -1, sizeof dp);
    for(int i = 1; i <= n; i++)
    	cin >> c[i];
    for(int u, v, w, i = 0; i < m; i++) {
    	cin >> u >> v >> w;
    	g[u].push_back({v, w});
    	rev[v].push_back({u, w});
    }
    for(int t, x, y, i = 0; i < k; i++) {
    	cin >> t >> x >> y;
    	gift[x][t] = y;
    }
    priority_queue<array<ll, 3>, vector<array<ll, 3>>, greater<>> pq;
    dp[1][0][0] = c[1] + gift[1][0];
    pq.push({dp[1][0][0], 0, 1});
    while(!pq.empty()) {
    	auto [dt,t, v] = pq.top();
    	pq.pop();
    	if(dp[v][t][0] != dt)
    		continue;
    	for(auto &[u, w] : g[v]) if(t + w <= l) {
    		if(dp[u][t + w][0] == -1) {
    			dp[u][t + w][0] = dp[v][t][0] + c[u] + gift[u][t + w];
    			pq.push({dp[u][t + w][0], t + w, u});
    		}
    	}
    }
    if(dp[1][l][0] != -1)
    	ans = max(ans, dp[1][l][0]);
    cout << (ans == 0 ? -1 : ans) << '\n';
    return 0;
}