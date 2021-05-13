#include <bits/stdc++.h>
using namespace std;
struct BIT {
    int n;
    vector<int> bit;
    void init(int x) {
        n = x;
        bit.resize(n + 2,0);
    }
    void init(vector<int> &a) {
        n = a.size();
        bit.resize(n+2, 0);
        for(int i = 1; i <= n; i++) {
			bit[i] += a[i - 1]; //check this
			if(i + (i & -i) <= n)
				bit[i + (i & -i)] += bit[i];
		}
    }
    int qry(int x) {
        x = min(x, n);
        int ans = 0;
        for(; x > 0; x -= (x & -x))
            ans += bit[x];
        return ans;
    }
    void upd(int x, int v = 1) {
        if(x <= 0) return;
        for(; x <= n; x += (x & -x))
            bit[x] += v;
    }
    int qry(int l, int r) { return qry(r) - qry(l - 1); }
};

const int mxn = 200 * 1000 + 3;
vector<int> g[mxn];
int sz[mxn], n, k[2], t, depth;
BIT cnt;
bool cent[mxn];
long long ans = 0;

int dfssz(int v, int p = -1) {
	sz[v] = 1;
	for(int u : g[v]) if(u != p && !cent[u])
		sz[v] += dfssz(u, v);
	return sz[v];
}

int fcent(int v, int p = -1) {
	for(int u : g[v]) if(u != p && !cent[u])
		if(2 * sz[u] > t)
			return fcent(u, v);
	return v;
}

void dfs(int v, int p, int d, bool upd) {
	if(d > max(k[0], k[1])) return;
	depth = max(depth, d);
	if(upd)
		cnt.upd(d);
	else
		ans += cnt.qry();
	for(int u : g[v]) if(u != p && !cent[u])
		dfs(u, v, d + 1, upd);
}

void decompose(int v, int p = -1) {
	t = dfssz(v);
	int centroid = fcent(v);
	cnt[0] = 1; depth = 0;
	cent[centroid] = true;
	for(int u : g[centroid]) if(u != p && !cent[u]) {
		dfs(u, centroid, 1, false);
		dfs(u, centroid, 1, true);
	}
	for(int i = 0; i <= depth; i++)
		cnt[i] = 0;
	for(int u : g[centroid]) if(u != p && !cent[u])
		decompose(u, centroid);
}

signed main() {
    std::ios::sync_with_stdio(0);
    std::cout.tie(0);
    std::cin.tie(0);
    #ifdef saarang
    freopen("/home/saarang/Documents/cp/input.txt", "r", stdin);
    freopen("/home/saarang/Documents/cp/output.txt", "w", stdout);
    #endif
    cnt.init(N);
    cin >> n >> k[0] >> k[1];
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    decompose(1);
    cout << ans << '\n';
    return 0;
}