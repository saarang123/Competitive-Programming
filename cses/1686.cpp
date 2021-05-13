#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mxn = 100 * 1000 + 2;
int a[mxn], c[mxn], dp[mxn];
vector<int> g[mxn], gt[mxn], scc[mxn];
vector<int> order, id;
vector<bool> used;
int idx, cost;

void dfs(int v) {
	used[v] = true;
	for(int u : g[v])
		if(!used[u])
			dfs(u);
	order.push_back(v);
}

void fin(int v) {
	used[v] = true;
	id[v] = idx;
    cost += a[v];
	for(int u : gt[v]) 
		if(!used[u])
			fin(u);
}

void dag(int v) {
    used[v] = true;
    for(int u : g[v]) {
        if(!used[u])
            dag(u);
        if(id[u] != id[v])
            scc[id[v]].push_back(id[u]);
    }
}

int f(int v) {
    if(dp[v] != -1)
        return dp[v];
    dp[v] = c[v];
    for(int u : scc[v]) {
        dp[v] = max(dp[v], c[v] + f(u));
    }
    return dp[v];
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
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int u, v, i = 0; i < m; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	gt[v].push_back(u);
    }
    used.assign(n + 1, false);
    id.resize(n + 1);
    for(int i = 1; i <= n; i++)
    	if(!used[i])
    		dfs(i);
    reverse(order.begin(), order.end());
    used.assign(n + 1, false);
    for(int v : order)
    	if(!used[v]) {
            ++idx;
    		fin(v);
            c[idx] = cost;
            cost = 0;
    	}
    used.assign(n + 1, false);
    for(int i = 1; i <= n; i++)
        if(!used[i])
            dag(i);
    memset(dp, -1, sizeof dp);
    int ans = 0;
    for(int i = 1; i <= idx; i++)
        ans = max(ans, f(i));
    cout << ans << '\n';
    return 0;
}