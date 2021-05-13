#include <bits/stdc++.h>
using namespace std;
const int mxn = 200 * 1000 + 3;
const int mxc = 21;
vector<int> g[mxn];
int sz[mxn], a[mxn], cnt[1 << mxc], ans[mxn], sum[mxn];
bool cent[mxn];
int n, start;

int dfssz(int v, int p) {
	sz[v] = 1;
	for(int u : g[v]) if(u != p && !cent[u])
		sz[v] += dfssz(u, v);
	return sz[v];
}

int fcent(int v, int p, int o) {
	for(int u : g[v]) if(u != p && !cent[u])
		if(2 * sz[u] > o)
			return fcent(u, v, 0);
	return v;
}

void upd(int v, int p, int c, int x = 1) {
	c ^= a[v];
	cnt[c] += x;
	for(int u : g[v]) if(u != p && !cent[u]) 
		upd(u, v, c);
}

void calc(int v, int p, int c = 0) {
	c ^= a[v];
	for(int i = 0; i < 20; i++)
		sum[v] += cnt[c ^ (1 << i)];
	sum[v] += c;
	for(int u : g[v]) if(u != p && !cent[u])
		calc(u, v, c);
	ans[v] += sum[v];
	sum[p] += sum[v];
	sum[v] = 0;
}

void decompose(int v, int p) {
	int centroid = fcent(v, -1, dfssz(v, -1));
	cent[centroid] = true;
	cnt[a[v]] = true;
	for(int u : g[centroid]) if(u != p && !cent[u])
		upd(u, v, a[v], 1);
	for(int u : g[centroid]) if(u != p && !cent[u]) {
		upd(u, v, a[v], -1);
		calc(u, v);
		upd(u, v, a[v], 1);
	}
	for(int u : g[centroid]) if(u != p && !cent[u])
		upd(u, v, a[v], -1);
	ans[v] += sum[v] >> 1;
	sum[v] = 0;
	cnt[a[v]]++;
	for(int u : g[centroid]) if(u != p && !cent[u])
		calc(u, v);
	ans[v] += sum[v];
	cnt[a[v]]--;
	for(int u : g[centroid]) if(u != p && !cent[u])
		decompose(u, v);
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
    for(int u, v, i = 1; i < n; i++) {
    	cin >> u >> v;
    	g[u].push_back(v);
    	g[v].push_back(u);
    }
    for(int i = 1; i <= n; i++) {
    	char c; cin >> c;
    	a[i] = 1 << (c - 'a');
    }
    decompose(1, -1);
    for(int i = 1; i <= n; i++)
    	cout << ans[i] << ' ';
    cout << '\n';
    return 0;
}