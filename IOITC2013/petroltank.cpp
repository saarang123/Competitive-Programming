#include <bits/stdc++.h>
using namespace std;
struct DSU {
    int n;
    vector<int> e;
    DSU(int _) : n(_), e(_ + 1, -1) {}
    inline int root(int x) {
        return (e[x] < 0 ? x : (e[x] = root(e[x])));
    }
    inline bool same(int x, int y) { return root(x) == root(y); }
    inline bool join(int x, int y) {
        x = root(x), y = root(y); if(x == y) return false;
        if(e[y] < e[x]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

const int mxn = 100'003, lgn = 18;
vector<array<int, 2>> g[mxn];
int dt[mxn], up[mxn][lgn], mx[mxn][lgn];
int n, m, q;

void init(int v = 1, int p = 1) {
	up[v][0] = p;
	for(int i = 1; i < lgn; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		mx[v][i] = max(mx[up[v][i - 1]][i - 1], mx[v][i - 1]);
	}
	for(auto &[u, w] : g[v]) if(u != p) {
		dt[u] = dt[v] + 1;
		mx[u][0] = w;
		init(u, v);
	}
}

array<int, 2> kth(int v, int di) {
	int res = 0;
	for(int i = 0; i < lgn; i++) {
		if(di >> i & 1) {
			res = max(res, mx[v][i]); v = up[v][i];
		}
	}
	return {v, res};
}

int lca(int a, int c) {
	if(dt[a] > dt[c]) swap(a, c);
	auto [b, ans] = kth(c, dt[c] - dt[a]);
	if(a == b)
		return ans;
	for(int i = lgn - 1; i >= 0; i--) {
		if(up[a][i] != up[b][i]) {
			ans = max({ans, mx[a][i], mx[b][i]});
			a = up[a][i]; b = up[b][i];
		}
	}
	ans = max({ans, mx[a][0], mx[b][0]});
	return ans;
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
    DSU uf(n);
    vector<array<int, 3>> ed(m);
    for(auto &[w, u, v] : ed)
    	cin >> u >> v >> w;
    sort(ed.begin(), ed.end());
    for(auto &[w, u, v] : ed) {
    	if(uf.join(u, v)) {
    		g[u].push_back({v, w});
    		g[v].push_back({u, w});
    	}
    }
    init();
    cin >> q;
    while(q--) {
    	int u, v;
    	cin >> u >> v;
    	cout << lca(u, v) << '\n';
    }
    return 0;
}