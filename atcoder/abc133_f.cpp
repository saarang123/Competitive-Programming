#include <bits/stdc++.h>
using namespace std;
const int mxn = 100'003, lgn = 18;
vector<array<int, 2>> subtract_col[mxn], add_col[mxn];
int up[mxn][lgn], dt[mxn], cnt[mxn], sum[mxn], ans[mxn], query_lca[mxn], depth[mxn];
vector<array<int, 3>> g[mxn], subtract[mxn], add[mxn];
vector<int> root_sum[mxn];
int n, q;

void init(int v = 1, int p = 1, int d = 0) {
	depth[v] = d;
	up[v][0] = p;
	for(int i = 1; i < lgn; i++)
		up[v][i] = up[up[v][i - 1]][i - 1];
	for(auto &[u, c, w] : g[v]) if(u != p) {
		dt[u] = dt[v] + 1;
		init(u, v, d + w);
	}
}

int kth(int v, int diff) {
	for(int i = 0; i < lgn; i++)
		if(diff >> i & 1)
			v = up[v][i];
	return v;
}

int lca(int u, int v) {
	if(dt[u] > dt[v]) swap(u, v);
	v = kth(v, dt[v] - dt[u]);
	if(u == v) 
		return u;
	for(int i = lgn - 1; i >= 0; i--)
		if(up[u][i] != up[v][i])
			u = up[u][i], v = up[v][i];
	return up[u][0];
}


void dfs(int v = 1, int p = -1) {
	for(auto id : root_sum[v])
		ans[id] += depth[v] - depth[query_lca[id]];

	for(auto &[x, y, id] : subtract[v])
		ans[id] -= 2 * cnt[x] * y;
	for(auto &[x, y, id] : add[v])
		ans[id] += cnt[x] * y;

	for(auto &[x, id] : subtract_col[v])
		ans[id] += 2 * sum[x];
	for(auto &[x, id] : add_col[v])
		ans[id] -= sum[x];

	for(auto &[u, c, w] : g[v]) if(u != p) {
		cnt[c]++;
		sum[c] += w;
		dfs(u, v);
		cnt[c]--;
		sum[c] -= w;
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
    cin >> n >> q;
    for(int u, v, c, d, i = 1; i < n; i++) {
    	cin >> u >> v >> c >> d;
    	g[u].push_back({v, c, d});
    	g[v].push_back({u, c, d});
    }
    init();
    for(int i = 0; i < q; i++) {
    	int u, v, x, y;
    	cin >> x >> y >> u >> v;

    	query_lca[i] = lca(u, v);
    	//cout << "LCA of u and v: " << query_lca[i] << '\n';

    	subtract[query_lca[i]].emplace_back(array<int, 3>{x, y, i});  //color counts
    	add[u].emplace_back(array<int, 3>{x, y, i});
    	add[v].emplace_back(array<int, 3>{x, y, i});

    	root_sum[u].emplace_back(i);
    	root_sum[v].emplace_back(i);  //depths

    	subtract_col[query_lca[i]].push_back({x, i});  //color weights
    	add_col[u].push_back({x, i});
    	add_col[v].push_back({x, i});
    }
    dfs();

    for(int i = 0; i < q; i++)
    	cout << ans[i] << '\n';
    return 0;
}