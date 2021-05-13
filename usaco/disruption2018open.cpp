#include <bits/stdc++.h>
using namespace std;
struct dsu {
	map<int, int> par, sz;
	void init(int v) {
		if(!par.count(v))
			par[v] = v; sz[v] = 1;
	}
	int find(int v) {
		if(par.count(v))
			return par[v] == v ? v : par[v] = find(par[v]);
		return v;
	};
	bool merge(int a, int b) {
		a = find(a); b = find(b);
		if(a == b)
			return false;
		if(sz[a] < sz[b]) swap(a, b);
		sz[a] += sz[b];
		par[b] = a;
		return true;
	}
	int size() {
		return par.size();
	}
};

const int mxn = 50 * 1000 + 3;
vector<array<int, 2>> g[mxn], ed[mxn];
int ans[mxn], n, m;
dsu uf[mxn];
set<array<int, 3>> os[mxn];

void dfs(int v, int p) {
	uf[v].init(v);
	for(auto &[u, id] : g[v]) if(u != p) {
		dfs(u, v);
		while(!os[u].empty()) {
			auto &[w, l, r] = *os[u].begin();
			if(uf[u].find(l) != uf[u].find(r)) {
				ans[id] = w; break;
			}
			os[u].erase(os[u].begin());
		}
		if(uf[u].size() > uf[v].size())
			swap(uf[u], uf[v]);
		for(auto &[nd, rt] : uf[u].par) {
			uf[v].init(nd);
			uf[v].merge(v, nd);
		}
		uf[v].init(u); uf[v].merge(u, v);
	}
	for(auto &[u, w] : ed[v])
		if(uf[v].find(v) != uf[v].find(u))
			os[v].insert({w, u, v});
	for(auto &[u, id] : g[v]) if(u != p) {
		if(os[v].size() < os[u].size()) swap(os[v], os[u]);
		for(auto &[w, l, r] : os[u])
			if(uf[v].find(l) != uf[v].find(r))
				os[v].insert({w, l, r});
	}
}

void usaco(string name) {
	freopen((name + ".in").c_str(), "r", stdin);
    freopen((name + ".out").c_str(), "w", stdout);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef saarang
    usaco("disrupt");
    #endif
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    memset(ans, -1, sizeof ans);
    for(int u, v, i = 0; i < n - 1; i++) {
    	cin >> u >> v;
    	g[u].push_back({v, i});
    	g[v].push_back({u, i});
    }
    for(int u, v, w, i = 0; i < m; i++) {
    	cin >> u >> v >> w;
    	ed[u].push_back({v, w});
    	ed[v].push_back({u, w});
    }
    dfs(1, -1);
    for(int i = 0; i < n - 1; i++)
    	cout << ans[i] << '\n';
    return 0;
}