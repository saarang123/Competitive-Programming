#include <bits/stdc++.h>
using namespace std;

struct UFDS {
    int n, c;
    vector<int> len, par;
    void init(int x, int y = 1) {
        n = x;
        c = y;
        par.resize(n+2);
        len.assign(n+2, 1);
        iota(par.begin(), par.end(), 0);
    }
    int fin(int v) { return par[v] == v ? v : par[v] = fin(par[v]); }
    bool join(int a, int b) {
        a = fin(a); b = fin(b);
        if(a == b) return false;
        if(c && len[a] < len[b])
            swap(a, b);
        par[b] = a;
        if(c) len[a] += len[b];
        return true;
    }
    int sz(int x) { return len[fin(x)]; }
};

const int mxn = 300 * 1000 + 2;
vector<int> g[mxn], tree[mxn];
int tin[mxn], low[mxn], dt[mxn], tx, n, m, ans = 0;
vector<array<int, 2>> bridges;
UFDS uf;

void dfs(int v, int p) {
	low[v] = tin[v] = ++tx;
	for(int u : g[v]) if(u != p) {
		if(tin[u] == -1) {
			dfs(u, v);
			low[v] = min(low[v], low[u]);
			if(low[u] > tin[v]) {
				bridges.push_back({u, v});
			} else {
				uf.join(u, v);
			}
		} else {
			low[v] = min(low[v], tin[u]);
			uf.join(u, v);
		}
	}
}

void diam(int v, int p, int d) {
	dt[v] = d;
	for(int u : tree[v]) if(u != p) 
		diam(u, v, d + 1);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    uf.init(n);
    memset(tin, -1, sizeof tin);
    memset(low, -1, sizeof low);
    for(int u, v, i = 0; i < m; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    dfs(1, -1);
    // for(int i = 1; i <= n; i++)
    // 	cout << uf.fin(i) << ' ';
    // cout << '\n';
    for(auto &[x, y] : bridges) {
    	int u = uf.fin(x), v = uf.fin(y);
    	tree[u].push_back(v);
    	tree[v].push_back(u);
    }
    diam(uf.fin(1), -1, 0);
    int id = 1;
    for(int i = 1; i <= n; i++)
    	if(dt[i] > dt[id])
    		id = i;
    diam(id, -1, 0);
    for(int i = 1; i <= n; i++)
    	ans = max(ans, dt[i]);
    cout << ans << '\n';
    return 0;
}