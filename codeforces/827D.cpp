#include <bits/stdc++.h>
using namespace std;

struct DSU {
    int n;
    vector<int> e;
    DSU(int _) : n(_) {
        e = vector<int>(n + 1, -1);
    }
    inline int root(int x) {
        return (e[x] < 0 ? x : (e[x] = root(e[x])));
    }
    inline bool same(int x, int y) {
        return root(x) == root(y);
    }
    inline bool join(int x, int y) {
        x = root(x), y = root(y); if(x == y) return false;
        if(e[y] < e[x]) swap(x, y);
        e[x] += e[y];
        e[y] = x;
        return true;
    }
};

const int mxn = 200 * 1000 + 3, lgn = 18;
int up[mxn][lgn], mx[mxn][lgn], dt[mxn], ans[mxn];
vector<array<int, 3>> g[mxn];
set<array<int, 2>> wt[mxn];
int n, m;

void init(int v = 1, int p = 1) {
	up[v][0] = p;
	for(int i = 1; i < lgn; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		mx[v][i] = max(mx[up[v][i - 1]][i - 1], mx[v][i - 1]);
	}
	for(auto &[u, w, id] : g[v]) if(u != p) {
		dt[u] = dt[v] + 1;
		mx[u][0] = w;
		init(u, v);
	}
}

array<int, 2> kth(int v, int di) {
	int x = 0;
	for(int i = 0; i < lgn; i++)
		if(di >> i & 1) {
			x = max(x, mx[v][i]); v = up[v][i];
		}
	return {v, x};
}

array<int, 2> lca(int a, int b) {
	if(dt[a] > dt[b])
		swap(a, b);
	auto [c, res] = kth(b, dt[b] - dt[a]);
	if(a == c)
		return {a, res};
	for(int i = lgn - 1; i >= 0; i--) 
		if(up[a][i] != up[c][i]) {
			res = max({res, mx[a][i], mx[c][i]});
			a = up[a][i]; c = up[c][i];
		}
	res = max({res, mx[a][0], mx[c][0]});
	return {up[a][0], res};
}

void dfs(int v = 1, int p = -1) {
	for(auto &[u, w, i] : g[v]) if(u != p) {
		dfs(u, v);
		if(wt[u].empty()) 
			ans[i] = -1; //bridge
		else 
			ans[i] = (*wt[u].begin())[0] - 1; //min other edges
		if(wt[u].size() > wt[v].size())
			swap(wt[u], wt[v]);
		for(auto ed : wt[u]) {
			if(wt[v].count(ed))
				wt[v].erase(ed);  //now in connected comp
			else
				wt[v].insert(ed); //extra
		}
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
    cin >> n >> m;
    DSU uf(n);
    vector<array<int, 4>> ed(m);
    for(int i = 0; i < m; i++) {
    	cin >> ed[i][1] >> ed[i][2] >> ed[i][0];
    	ed[i][3] = i;
    	ans[i] = -2;
    }
    sort(ed.begin(), ed.end());
    for(auto &[w, u, v, i] : ed) {
    	if(uf.join(u, v)) {
    		g[u].push_back({v, w, i});
    		g[v].push_back({u, w, i});
    	} else {
    		wt[u].insert({w, i});
    		wt[v].insert({w, i});
    	}
    }
    init();
    dfs();
    for(auto &[w, u, v, i] : ed) if(ans[i] < -1) 
    	ans[i] = lca(u, v)[1] - 1;

    for(int i = 0; i < m; i++) 
    	cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}