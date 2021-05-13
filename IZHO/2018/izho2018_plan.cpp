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
const int mxn = 100 * 1000 + 3, lgn = 18;
vector<array<int, 2>> adj[mxn], g[mxn];
int dt[mxn], dist[mxn], up[mxn][lgn], mx[mxn][lgn];
int n, m;

void init(int v = 1, int p = 1) {
	up[v][0] = p;
	for(int i = 1; i < lgn; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		mx[v][i] = min(mx[up[v][i - 1]][i - 1], mx[v][i - 1]);
	}
	for(auto &[u, w] : g[v]) if(u != p) {
		dt[u] = dt[v] + 1;
		mx[u][0] = w;
		init(u, v);
	}
}

array<int, 2> kth(int v, int di) {
	int x = dist[0];
	for(int i = 0; i < lgn; i++)
		if(di >> i & 1) {
			x = min(x, mx[v][i]); v = up[v][i];
		}
	return {v, x};
}

int query(int a, int b) {
	if(dt[a] > dt[b])
		swap(a, b);
	auto [c, res] = kth(b, dt[b] - dt[a]);
	if(a == c)
		return res;
	for(int i = lgn - 1; i >= 0; i--) 
		if(up[a][i] != up[c][i]) {
			res = min({res, mx[a][i], mx[c][i]});
			a = up[a][i]; c = up[c][i];
		}
	res = min({res, mx[a][0], mx[c][0]});
	return res;
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
    memset(dist, 0x7f, sizeof dist);
    vector<array<int, 3>> ed;
    for(int u, v, w, i = 0; i < m; i++) {
    	cin >> u >> v >> w;
    	adj[u].push_back({v, w});
    	adj[v].push_back({u, w});
    	ed.push_back({w, u, v});
    }

    priority_queue<array<int, 2>, vector<array<int, 2>>, greater<>> pq;
    int k; cin >> k;
    for(int x, i = 0; i < k; i++) {
    	cin >> x;
    	dist[x] = 0;
    	pq.push({0, x});
    }
    while(!pq.empty()) {
    	auto [wt, v] = pq.top(); pq.pop();
    	if(dist[v] != wt) continue;
    	for(auto &[u, w] : adj[v]) if(dist[v] + w < dist[u]) {
    		dist[u] = dist[v] + w;
    		pq.push({dist[u], u});
    	}
    }

    for(auto &[w, u, v] : ed)
    	w = min(dist[u], dist[v]);
    sort(ed.begin(), ed.end(), greater<>());
    DSU uf(n);
    for(auto &[w, u, v] : ed) {
    	if(uf.join(u, v)) {
    		g[u].push_back({v, w});
    		g[v].push_back({u, w});
    	}
    }

    init();
    int q; cin >> q;
    while(q--) {
    	int u, v;
    	cin >> u >> v;
    	cout << query(u, v) << '\n';
    }
    return 0;
}