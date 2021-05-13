#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 3;
vector<int> g[mxn];
set<array<int, 2>> dir;
int dp[mxn], tin[mxn], tout[mxn], a[mxn], par[mxn];
int n, tx, ans;
vector<int> col[mxn], id[mxn];

void dfs(int v, int p) {
	tin[v] = ++tx;
	par[v] = p;
	for(int u : g[v]) if(u != p) 
		dfs(u, v);
	tout[v] = tx;
}

void init(int v) {
	int sum = 1;
	for(int u : g[v]) if(u != par[v]) {
		int cnt = upper_bound(col[a[v]].begin(), col[a[v]].end(), tout[u]) 
					- lower_bound(col[a[v]].begin(), col[a[v]].end(), tin[u]);
		if(cnt > 0) 
			dir.insert({v, u});
		sum += cnt;
	}
	int left = col[a[v]].size() - sum;
	if(left > 0) 
		dir.insert({v, par[v]});
}

int setup(int v) {
	for(int u : g[v]) if(u != par[v])
		dp[v] += setup(u);
	return dp[v] + dir.count({v, par[v]});
}

void reroot(int v) {
	ans += dp[v] == dir.size();
	for(int u : g[v]) if(u != par[v]) {
		dp[v] -= dp[u];
		dp[v] -= dir.count({u, v});
		dp[u] += dp[v];
		dp[u] += dir.count({v, u});
		reroot(u);
		dp[u] -= dir.count({v, u});
		dp[u] -= dp[v];
		dp[v] += dir.count({u, v});
		dp[v] += dp[u];
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
    cin >> n;
    vector<int> b;
    for(int i = 1; i <= n; i++) {
    	cin >> a[i];
    	b.push_back(a[i]);
    }
    sort(b.begin(), b.end());
    b.resize(unique(b.begin(), b.end()) - b.begin());
    for(int i = 1; i <= n; i++) {
    	a[i] = upper_bound(b.begin(), b.end(), a[i]) - b.begin();
    	id[a[i]].push_back(i);
    }
    for(int i = 1; i < n; i++) {
    	int u, v;
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1, -1);
    for(int i = 1; i <= b.size(); i++) {
    	if(id[i].size() == 1) continue;
    	for(int v : id[i]) 
    		col[i].push_back(tin[v]);
    	sort(col[i].begin(), col[i].end());
    	for(int v : id[i])
    		init(v);
    }
    setup(1);
    reroot(1);
    cout << ans << '\n';
    return 0;
}