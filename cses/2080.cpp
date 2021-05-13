#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 3;
vector<int> g[mxn];
int cnt[mxn], sz[mxn], n, k, t, depth;
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
	if(d > k) return;
	depth = max(depth, d);
	if(upd)
		cnt[d]++;
	else
		ans += cnt[k - d];
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
    cin >> n >> k;
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    decompose(1);
    cout << ans << '\n';
    return 0;
}