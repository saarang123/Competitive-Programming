#include <bits/stdc++.h>
using namespace std;
#define int long long

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

const int N = 2e5 + 2;
const int LGN = 20;
vector<array<int, 2>> g[N];
int d[N], dt[N], up[N][LGN], mx[N][LGN];
int n, m;

void dfs(int v, int p, int depth) {
	up[v][0] = (p == -1 ? v : p);
	d[v] = (p == -1 ? 0 : d[p] + 1);
	dt[v] = depth;
	for(int i = 1; i < LGN; i++) {
		up[v][i] = up[up[v][i - 1]][i - 1];
		mx[v][i] = max(mx[up[v][i - 1]][i - 1], mx[v][i - 1]);
	}
	for(auto ed : g[v]) {
		int u = ed[0], w = ed[1];
		if(u == p) continue;
		mx[u][0] = w;
		dfs(u, v, depth + w);
	}
}

array<int, 2> kth(int a, int k) {
	int mxm = 0;
	for(int i = 0; i < LGN; i++)
		if(k >> i & 1) {
			mxm = max(mxm, mx[a][i]);
			a = up[a][i];
		}
	return {a, mxm};
}

array<int, 2> LCA(int a, int b) {
	if(d[a] < d[b]) swap(a, b);
	auto lift = kth(a, d[a] - d[b]);
	a = lift[0]; int ans = lift[1];
	if(a == b) return {a, ans};
	for(int i = LGN - 1; i >= 0; i--) {
		if(up[a][i] != up[b][i]) {
			ans = max(ans, max(mx[a][i], mx[b][i]));
			a = up[a][i]; b = up[b][i];
		}
	}
	assert(up[a][0] == up[b][0]);
	ans = max(ans, max(mx[a][0], mx[b][0]));
	return {up[a][0], ans};
}

int dist(int a, int b) { return dt[a] + dt[b] - 2 * dt[LCA(a, b)[0]]; }

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/input.txt", "r", stdin);
    freopen("C:/Users/shriya-student/Documents/competitive programming/newproj/output.txt", "w", stdout);
    #endif
    cin >> n >> m;
    UFDS dsu; dsu.init(n);
    vector<array<int, 4>> ed(m);
    vector<bool> used(m);
    vector<int> ans(m);
    for(int i = 0; i < m; i++) cin >> ed[i][1] >> ed[i][2] >> ed[i][0], ed[i][3] = i;
    sort(ed.begin(), ed.end());
	int cost = 0;
	for(auto edge : ed) {
		int w = edge[0], u = edge[1], v = edge[2], id = edge[3];
		if(dsu.join(u, v)) {
			used[id] = true;
			cost += w;
			g[u].push_back({v, w});
			g[v].push_back({u, w});
		}
	}
	dfs(1, -1, 0);
	for(auto edge : ed) {
		int w = edge[0], u = edge[1], v = edge[2], id = edge[3];
		if(used[id]) ans[id] = cost;
		else ans[id] = cost - LCA(u, v)[1] + w;
	}
	for(int x : ans) cout << x << '\n';
    return 0;
}